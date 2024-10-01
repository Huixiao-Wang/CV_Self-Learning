// curve_fitting_per_frame.cpp
#include <ceres/ceres.h>
#include <iostream>
#include <vector>
#include <utility>
#include <random>

// 残差块，定义线性模型的残差 y - (a * x + b)
struct LinearCostFunctor
{
    LinearCostFunctor(double x, double y) : x_(x), y_(y) {}

    template <typename T>
    bool operator()(const T *const ab, T *residual) const
    {
        // ab[0] = a, ab[1] = b
        residual[0] = T(y_) - (ab[0] * T(x_) + ab[1]);
        return true;
    }

private:
    const double x_;
    const double y_;
};

// 生成带噪声的线性数据
std::vector<std::pair<double, double>> GenerateNoisyData(double a, double b, int num_points, double noise_std)
{
    std::vector<std::pair<double, double>> data;
    std::default_random_engine generator;
    std::normal_distribution<double> distribution(0.0, noise_std);

    for (int i = 0; i < num_points; ++i)
    {
        double x = static_cast<double>(i);
        double y = a * x + b + distribution(generator);
        data.emplace_back(x, y);
    }

    return data;
}

int main()
{
    // 模拟多帧数据参数
    const int num_frames = 10;       // 总帧数
    const int points_per_frame = 50; // 每帧的数据点数
    const double true_a = 2.0;       // 真正的斜率
    const double true_b = 5.0;       // 真正的截距
    const double noise_std = 1.0;    // 噪声标准差

    // 存储每一帧的拟合参数
    std::vector<std::pair<double, double>> fitted_parameters;

    // 初始参数猜测
    double ab[2] = {0.0, 0.0}; // ab[0] = a, ab[1] = b

    for (int frame = 0; frame < num_frames; ++frame)
    {
        // 生成当前帧的带噪声数据
        std::vector<std::pair<double, double>> data = GenerateNoisyData(true_a, true_b, points_per_frame, noise_std);

        // 构建优化问题
        ceres::Problem problem;
        for (const auto &point : data)
        {
            ceres::CostFunction *cost_function = new ceres::AutoDiffCostFunction<LinearCostFunctor, 1, 2>(
                new LinearCostFunctor(point.first, point.second));
            problem.AddResidualBlock(cost_function, nullptr, ab);
        }

        // 配置求解器
        ceres::Solver::Options options;
        options.linear_solver_type = ceres::DENSE_QR;
        options.minimizer_progress_to_stdout = false; // 设为 true 可查看每帧的优化过程
        options.max_num_iterations = 100;

        // 求解
        ceres::Solver::Summary summary;
        ceres::Solve(options, &problem, &summary);

        // 存储当前帧的拟合参数
        fitted_parameters.emplace_back(ab[0], ab[1]);

        // 输出当前帧的结果
        std::cout << "Frame " << frame + 1 << ":\n";
        std::cout << "  Estimated a: " << ab[0] << ", b: " << ab[1] << "\n";
        std::cout << "  Summary: " << summary.BriefReport() << "\n\n";
    }

    // 输出所有帧的拟合参数
    std::cout << "All fitted parameters per frame:\n";
    for (size_t i = 0; i < fitted_parameters.size(); ++i)
    {
        std::cout << "Frame " << i + 1 << ": a = " << fitted_parameters[i].first
                  << ", b = " << fitted_parameters[i].second << "\n";
    }

    return 0;
}
