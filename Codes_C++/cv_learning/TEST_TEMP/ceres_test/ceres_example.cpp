#include "ceres/ceres.h"
#include "glog/logging.h"

// 定义残差函数，y = 10 - x
struct CostFunctor
{
    template <typename T>
    bool operator()(const T *const x, T *residual) const
    {
        residual[0] = 10.0 - x[0];
        return true;
    }
};

int main(int argc, char **argv)
{
    google::InitGoogleLogging(argv[0]);

    // 要优化的变量，初始值为 0.5
    double x = 0.5;

    // 构造优化问题
    ceres::Problem problem;
    problem.AddResidualBlock(
        new ceres::AutoDiffCostFunction<CostFunctor, 1, 1>(new CostFunctor),
        nullptr, &x);

    // 配置求解器
    ceres::Solver::Options options;
    options.linear_solver_type = ceres::DENSE_QR;
    options.minimizer_progress_to_stdout = true;

    // 求解问题
    ceres::Solver::Summary summary;
    ceres::Solve(options, &problem, &summary);

    // 输出结果
    std::cout << summary.BriefReport() << "\n";
    std::cout << "x : " << x << "\n";

    return 0;
}
