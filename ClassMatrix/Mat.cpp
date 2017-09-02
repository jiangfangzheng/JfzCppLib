/**
 * 蒋方正封装的Mat类
 * 2017-09-02
 */
#include "Mat.h"
#include <iostream>
#include <iomanip>
#include <valarray>

Mat::Mat()
{
	data.resize(1, 1);
	data.fill(0);
}

Mat::Mat(const int row, const int col)
{
	data.resize(row, col);
	data.fill(0);
}

Mat::Mat(const MatrixXd &matData)
{
	data.resize(matData.rows(), matData.cols());
	data = matData;
}

Mat::Mat(const double *p, const int row, const int col)
{
	data.resize(row, col);
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			data(i, j) = p[i*col + j];
		}
	}
}

Mat::Mat(const vector<vector<double>> &vetData)
{
	auto row = vetData.size();
	auto col = vetData.at(0).size();
	data.resize(row, col);
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			data(i, j) = vetData[i][j];
		}
	}
}

Mat::~Mat()
{
}

unsigned int Mat::size() const
{
	return data.size();
}

unsigned Mat::rows() const
{
	return data.rows();
}

unsigned Mat::cols() const
{
	return data.cols();
}

double Mat::operator()(const int i)
{
	return data(i);
}

double Mat::operator()(const int i, const int j)
{
	return data(i, j);
}

Mat& Mat::operator=(const Mat& mat_)
{
	data.resize(mat_.rows(), mat_.cols());
	data = mat_.data;
	return *this;
}

void Mat::resize(const int row, const int col)
{
	data.resize(row, col);
	data.fill(0);
}

void Mat::fill(const double value)
{
	data.fill(value);
}

bool Mat::mergeRow(Mat& addMat)
{
	if (data.cols() == addMat.cols())
	{
		Mat temp1(data);
		Mat temp2(addMat);
		data.resize(data.rows() + addMat.rows(), data.cols());
		data << temp1.data,
				temp2.data;
		return true;
	}
	return false;
}

bool Mat::mergeCol(Mat& addMat)
{
	if (data.rows() == addMat.rows())
	{
		Mat temp1(data);
		Mat temp2(addMat);
		data.resize(data.rows(), data.cols() + addMat.cols());
		data << temp1.data, temp2.data;
		return true;
	}
	return false;
}

bool Mat::add(Mat& addMat)
{
	if (data.rows() != addMat.rows() || data.cols() != addMat.cols())
		return false;
	data += addMat.data;
	return true;
}

bool Mat::sub(Mat& addMat)
{
	if (data.rows() != addMat.rows() || data.cols() != addMat.cols())
		return false;
	data -= addMat.data;
	return true;
}

bool Mat::mul(Mat& addMat)
{
	if (data.cols() != addMat.rows())
		return false;
	data *= addMat.data;
	return true;
}

bool Mat::mulk(const double k)
{
	data *= k;
	return true;
}

Mat Mat::t() const
{
	Mat temp;
	temp.data = this->data.transpose();
	return temp;
}

Mat Mat::inv() const
{
	if(data.determinant() > -0.0000001 && data.determinant() < 0.0000001)
	{
		Mat temp(data);
		temp.fill(0);
		return temp;
	}
	Mat temp(this->data.inverse());
	return temp;
}

double Mat::det() const
{
	return data.determinant();
}

void Mat::show(int precision)
{
	for (int i = 0; i < data.rows(); ++i)
	{
		for (int j = 0; j < data.cols(); ++j)
		{
			cout << fixed << setprecision(precision);
			cout << data(i, j) << "\t";
		}
		cout << endl;
	}
}

void Mat::show(Mat& mat, int precision)
{
	for (int i = 0; i < mat.data.rows(); ++i)
	{
		for (int j = 0; j < mat.data.cols(); ++j)
		{
			cout << fixed << setprecision(precision);
			cout << mat.data(i, j) << "\t";
		}
		cout << endl;
	}
}

void Mat::show(MatrixXd& data, int precision)
{
	for (int i = 0; i < data.rows(); ++i)
	{
		for (int j = 0; j < data.cols(); ++j)
		{
			cout << fixed << setprecision(precision);
			cout << data(i, j) << "\t";
		}
		cout << endl;
	}
}

void Mat::test()
{
	cout << "构造、析构" << endl;
	Mat A;
	A.show();
	cout << endl;
	Mat B(3, 4);
	B.show(6);
	cout << endl;
	MatrixXd inputXd;
	inputXd.resize(2, 3);
	inputXd <<	1, 2, 3,
				4, 5, 6;
	Mat C(inputXd);
	C.show();
	cout << endl;
	vector<vector<double>> vecData{ {1,2,3},{4,5,6},{7,8,10} };
	Mat D(vecData);
	D.show();
	cout << endl;
	double *p = new double[16];
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			p[i * 4 + j] = (i + 1)*(j + 1);
		}
	}
	Mat E(p, 4, 4);
	E.show();
	cout << endl;

	cout << "运算符重载" << endl;
	// 单个是行的开头元素，双个是数组下标
	cout << D(0) << " " << D(1) << " " << D(1, 1) << " " << D(2, 2) << endl << endl;
	Mat Dcopy;
	Dcopy.fill(0);
	Dcopy = D;
	D.show();
	cout << endl;
	Dcopy.show();
	cout << endl;

	cout << "显示、读取、保存" << endl;
	show(inputXd);
	cout << endl;
	show(D);
	cout << endl;

	cout << "基本操作" << endl;
	cout << "C.size() " << C.size() << endl;
	cout << "C.rows() " << C.rows() << endl;
	cout << "C.cols() " << C.cols() << endl;
	cout << "C.resize(3,3) " << endl;
	C.resize(3, 3);
	cout << "C.fill(7) " << endl;
	C.fill(7);
	C.show();

	cout << "取某行某列" << endl;

	cout << "合并矩阵" << endl;
	Mat F(inputXd);
	cout << "F.mergeRow(D)" << endl;
	F.show();
	cout << endl;
	D.show();
	cout << endl;
	F.mergeRow(D);
	F.show();
	cout << endl;
	cout << "C.mergeCol(D)" << endl;
	C.show();
	cout << endl;
	D.show();
	cout << endl;
	C.mergeCol(D);
	C.show();
	cout << endl;

	cout << "矩阵基本运算 + - * k* 转置 逆 行列式" << endl;
	vector<vector<double>> vecData1{ { 1,2,3 },{ 4,5,6 },{ 7,8,9 } };
	Mat H(vecData1);
	H.add(D);
	H.show();
	cout << endl;
	H.sub(D);
	H.show();
	cout << endl;
	H.mul(D);
	H.show();
	cout << endl;
	H.mulk(3);
	H.show();
	cout << endl;
	Mat I(H.t());
	I.show();
	cout << endl;
	Mat J(D.inv());
	J.show(6);
	cout << endl;
	cout << H.det() << endl << endl;
}