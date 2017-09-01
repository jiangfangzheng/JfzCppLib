#pragma once
#include <vector>
#include <Eigen>
using namespace std;
using namespace Eigen;

class Mat
{
public:
	// ��¶������֧��ԭ������
	MatrixXd data;

	// ���졢����
	Mat();
	Mat(const int row, const int col);
	explicit Mat(const MatrixXd &matData);
	explicit Mat(const double *p, const int row, const int col);
	explicit Mat(const vector<vector<double>> &vetData);
	virtual ~Mat();

	// ���������
	double operator()(const int i);
	double operator()(const int i, const int j);
	Mat& operator=(const Mat& mat_);

	// ��ʾ����ȡ������
	static void show(Mat &mat, int precision = 3);
	static void show(MatrixXd &data, int precision = 3);
	void show(int precision = 3);

	// ��������
	unsigned int size() const;
	unsigned int rows() const;
	unsigned int cols() const;
	void resize(const int row, const int col);
	void fill(const double value);

	// ȡĳ��\ĳ��

	// �ϲ�����
	bool mergeRow(Mat &addMat);
	bool mergeCol(Mat &addMat);

	// ����������� + - * k* ת�� �� ����ʽ
	bool add(Mat &addMat);
	bool sub(Mat &addMat);
	bool mul(Mat &addMat);
	bool mulk(const double k);
	Mat t() const;
	Mat inv() const;
	double det() const;

	// ͳ����Ϣ ���ֵ����Сֵ��ƽ��ֵ

	// ����
	static void test();
};
