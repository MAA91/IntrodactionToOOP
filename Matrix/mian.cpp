#include "stdafx.h"

class Matrix
{
private:
	int** matrix;
	int rows;
	int cols;
public:
	int** get_matrix()const { return matrix; }
	int get_rows()const { return rows; }
	int get_cols()const { return cols; }
	void set_matrix(int** matrix) { this->matrix = matrix; }
	void set_rows(int rows) { this->rows = rows; }
	void set_cols(int cols) { this->cols = cols; }

	Matrix(int rows = DEFAULT_ROWS, int cols = DEFAULT_COLS):rows(rows), cols(cols)
	{
		matrix = new int* [rows];
		for (int i = 0; i < rows; i++)
		{
			this->matrix[i] = new int[cols] {};
		}
	}
	Matrix(int** matrix, int rows, int cols):Matrix(rows, cols)
	{
		matrix = new int* [rows];
		for (int i = 0; i < rows; i++)
		{
			matrix[i] = new int[cols];
			for (int j = 0; j < cols; j++)
				this->matrix[i][j] = matrix[i][j];
		}
	}
	Matrix(const Matrix& other):Matrix(other.matrix, other.rows, other.cols)
	{
		matrix = new int* [rows];
		for (int i = 0; i < rows; i++)
		{
			matrix[i] = new int[cols];
			for (int j = 0; j < cols; j++)
				matrix[i][j] = other.matrix[i][j];
		}
	}
	~Matrix()
	{
		for (int i = 0; i < rows; i++)
			delete[] matrix[i];
		delete[] matrix;
	}

	void FillRand(int min = 0, int max = 9)
	{
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				matrix[i][j] = min + rand() % (max - min + 1);
	}

	Matrix& operator=(Matrix& other)
	{
		for (int i = 0; i < rows; i++)
			delete[] matrix[i];
		delete[] matrix;
		this->cols = other.cols;
		this->rows = other.rows;
		matrix = new int* [rows];
		for (int i = 0; i < rows; i++)
		{
			matrix[i] = new int[cols];
			for (int j = 0; j < cols; j++)
				this->matrix[i][j] = other.matrix[i][j];
		}
		return *this;
	}
	Matrix& operator=(int other)
	{
		matrix = new int* [rows];
		for (int i = 0; i < rows; i++)
		{
			matrix[i] = new int[cols];
			for (int j = 0; j < cols; j++)
				this->matrix[i][j] = other;
		}
		return *this;
	}
	Matrix& operator+=(int other)
	{
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				this->matrix[i][j] += other;
		return *this;
	}
	Matrix& operator+=(const Matrix& other)
	{
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				this->matrix[i][j] += other.matrix[i][j];
		return *this;
	}
	Matrix& operator-=(int other)
	{
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				this->matrix[i][j] -= other;
		return *this;
	}
	Matrix& operator-=(const Matrix& other)
	{
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < cols; j++)
				this->matrix[i][j] -= other.matrix[i][j];
		return *this;
	}
};

std::ostream& operator<<(std::ostream& os, const Matrix& obj)
{
	for (int i = 0; i < obj.get_rows(); i++)
	{
		for (int j = 0; j < obj.get_cols(); j++)
			cout << obj.get_matrix()[i][j] << " ";
		cout << endl;
	}
	return os;
}

void main()
{
	setlocale(0, "");
	srand(time(NULL));

	Matrix matrix1;
	matrix1.FillRand();
	Matrix matrix2(matrix1);
	cout << matrix1 << endl;
	cout << matrix2 << endl;
}