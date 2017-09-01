#pragma once
#include <vector>
#include <Eigen>
using namespace std;
using namespace Eigen;

class Mat
{
public:
	// 暴露数据以支持原生操作
	MatrixXd data;

	// 构造、析构
	Mat();
	Mat(const int row, const int col);
	explicit Mat(const MatrixXd &matData);
	explicit Mat(const double *p, const int row, const int col);
	explicit Mat(const vector<vector<double>> &vetData);
	virtual ~Mat();

	// 运算符重载
	double operator()(const int i);
	double operator()(const int i, const int j);
	Mat& operator=(const Mat& mat_);

	// 显示、读取、保存
	static void show(Mat &mat, int precision = 3);
	static void show(MatrixXd &data, int precision = 3);
	void show(int precision = 3);

	// 基本操作
	unsigned int size() const;
	unsigned int rows() const;
	unsigned int cols() const;
	void resize(const int row, const int col);
	void fill(const double value);

	// 取某行\某列

	// 合并矩阵
	bool mergeRow(Mat &addMat);
	bool mergeCol(Mat &addMat);

	// 矩阵基本运算 + - * k* 转置 逆 行列式
	bool add(Mat &addMat);
	bool sub(Mat &addMat);
	bool mul(Mat &addMat);
	bool mulk(const double k);
	Mat t() const;
	Mat inv() const;
	double det() const;

	// 统计信息 最大值、最小值、平均值

	// 测试
	static void test();
};
