    #include <vector>
	#include <iostream>
	#include "Matrix.hpp"
	using namespace std;
	
	namespace zich {
        
	 Matrix Matrix::operator+(const Matrix &other) {
	 if (this->rows != other.rows || this->col != other.col) {
	 throw invalid_argument("error");
	 }
	 vector<double> ans;
	 for (int i = 0; i < rows; i++) {
	    for (int j = 0; j < col; j++) {
	        ans.push_back((unsigned int) (this->vector1[(double) ((i * col) + j)] +other.vector1[(double) ((i * col) + j)]));
	    }
	 }
	 Matrix matrix(ans, other.rows, other.col);
	 return matrix;
	 }
	
	
	 Matrix &Matrix::operator+=(const Matrix &other) {
	 
	 if (other.rows != this->rows || other.col != this->col) {
	 throw invalid_argument("error");
	 }
	 for (int i = 0; i < other.rows; i++) {
	    for (int j = 0; j < other.col; j++) {
	        this->vector1[(double) ((i * col) + j)] += other.vector1[(double) ((i * col) + j)];
	    }
	 }
	 return *this;
	 }
	
	 Matrix operator+(Matrix &other) {
	 vector<double> ans;
	 for (int i = 0; i < other.rows; i++) {
	    for (int j = 0; j < other.col; j++) {
	        ans.push_back((double) other.vector1[(double) ((i * other.col) + j)]);
	    }
	 }
	 Matrix matrix(ans, other.rows, other.col);
	 return matrix;
	 }
	
	 Matrix Matrix::operator-(const Matrix &other) {
	 if (other.rows != this->rows || other.col != this->col) {
	 throw invalid_argument("error");
	 }
	 vector<double> ans;
	 for (int i = 0; i < other.rows; i++) {
	    for (int j = 0; j < other.col; j++) {
	        ans.push_back(this->vector1[(double) ((i * col) + j)] - other.vector1[(double) ((i * col) + j)]);
	    } 
	 }
	 Matrix matrix(ans, other.rows, other.col);
	 return matrix;
	 }
	
	 Matrix &Matrix::operator-=(const Matrix &other) {
	 if (other.rows != this->rows || other.col != this->col) {
	 throw invalid_argument("error");
	 }
	 for (int i = 0; i < other.rows; i++) {
	    for (int j = 0; j < other.col; j++) {
	        this->vector1[(double) ((i * col) + j)] -= other.vector1[(double) ((i * col) + j)];
	    }
	 }
	 return *this;
	 }
		
	 Matrix operator-(Matrix &other) {
	 vector<double> ans;
	 for (int i = 0; i < other.rows; i++) {
	     for (int j = 0; j < other.col; j++) {
	        ans.push_back((-1) * other.vector1[(double) ((i * other.col) + j)]);
	    }
	 }
	 Matrix matrix(ans, other.rows, other.col);
	 return matrix;
	 }
	
	 bool Matrix::operator>(Matrix &other) {
	 if (other.rows != this->rows || other.col != this->col) {
	 throw invalid_argument("error");
	 }
	 double ans = 0;
	 double ans_other = 0;
	 for (int i = 0; i < other.rows; i++) {
	    for (int j = 0; j < other.col; j++) {
	        ans = ans + this->vector1[(double) ((i * col) + j)];
	        ans_other += other.vector1[(double) ((i * col) + j)];
	    }
	 }
	 return ans > ans_other;
     }
	
	 bool Matrix::operator>=(Matrix &other) {
	 if (other.rows != this->rows || other.col != this->col) {
	 throw invalid_argument("error");
	 }
	 double ans = 0;
	 double ans_other = 0;
	 for (int i = 0; i < other.rows; i++) {
	    for (int j = 0; j < other.col; j++) {
	        ans = ans + this->vector1[(double) ((i * col) + j)];
	        ans_other += other.vector1[(double) ((i * col) + j)];
	    }
	 }
	 return ans >= ans_other;
	 }
	
	 bool Matrix::operator<(Matrix &other) {
	 if (other.rows != this->rows || other.col != this->col) {
	 throw invalid_argument("error");
	 }
	 double ans = 0;
	 double ans_other = 0;
	 for (int i = 0; i < other.rows; i++) {
	    for (int j = 0; j < other.col; j++) {
	        ans = ans + this->vector1[(double) ((i * col) + j)];
	        ans_other += other.vector1[(double) ((i * col) + j)];
	    }
	 }
	 return ans < ans_other;
	 }
	
	 bool Matrix::operator<=(Matrix &other) {
	 if (other.rows != this->rows || other.col != this->col) {
	 throw invalid_argument("error");
	 }
	 double ans = 0;
	 double ans_other = 0;
	 for (int i = 0; i < other.rows; i++) {
	    for (int j = 0; j < other.col; j++) {
	        ans = ans + this->vector1[(double) ((i * col) + j)];
	        ans_other += other.vector1[(double) ((i * col) + j)];
	    }
	 }
	 return ans <= ans_other;
	 }
	
	 bool Matrix::operator==(const Matrix &other) const {
	 if (other.rows != rows || other.col != col) {
	 throw invalid_argument("error");
	 }
	 for (int i = 0; i < rows; i++) {
	    for (int j = 0; j < col; j++) {
	        if (this->vector1[(double) ((i * col) + j)] != other.vector1[(double) ((i * col) + j)]) {
	            return false;
	        }
	    }
	 }
	 return true;
	 }
	
	 bool Matrix::operator!=(const Matrix &other) {
	 if (other.rows != rows || other.col != col) {
	 throw invalid_argument("error");
	 }
	 for (int i = 0; i < rows; i++) {
	     for (int j = 0; j < col; j++) {
	         if (this->vector1[(double) ((i * col) + j)] != other.vector1[(double) ((i * col) + j)]) {
	            return true;
	        }
	    }
	 }
	 return false;
	 }
	
     // prefix
	 Matrix &Matrix::operator++() {
	 for (int i = 0; i < this->rows; i++) {
	    for (int j = 0; j < this->col; j++) {
	     this->vector1[(double) ((i * col) + j)] += 1;
	    }
	  }
	 return *this;
	 }
	
	 //post
	 Matrix Matrix::operator++(int) {
	 Matrix same = *this;
	 for (int i = 0; i < this->rows; i++) {
	    for (int j = 0; j < this->col; j++) {
	     this->vector1[(double) ((i * col) + j)] += 1;
	    }
	 }
	 return same;
	 }
	
	 // prefix
	 Matrix &Matrix::operator--() {
	 for (int i = 0; i < this->rows; i++) {
	    for (int j = 0; j < this->col; j++) {
	        this->vector1[(double) ((i * col) + j)] -= 1;
	    }
	 }
	 return *this;
	 }
	
	 //post
	 Matrix Matrix::operator--(int) {
	 Matrix same = *this;
	 for (int i = 0; i < this->rows; i++) {
	    for (int j = 0; j < this->col; j++) {
	        this->vector1[(double) ((i * col) + j)] -= 1;
	    }
	 }
	 return same;
	 }
	
	 Matrix operator*(const double scalar, Matrix &other) {
	 vector<double> ans((unsigned long) (other.rows * other.col), 0);
	 for (int i = 0; i < other.rows; i++) {
	    for (int j = 0; j < other.col; j++) {
	        ans[(unsigned int) ((i * other.col) + j)] = (other.vector1[(double) ((i * other.col) + j)] *scalar);
	    }
	 }
	 Matrix matrix(ans, other.rows, other.col);
	 return matrix;
	 }
	
	 Matrix operator*(Matrix &other, const double scalar) {
	 vector<double> ans((unsigned long) (other.rows * other.col), 0);
	 for (int i = 0; i < other.rows; i++) {
	    for (int j = 0; j < other.col; j++) {
	        ans[(unsigned int) ((i * other.col) + j)] = (other.vector1[(double) ((i * other.col) + j)] *scalar);
	    }
	 }
	 Matrix matrix(ans, other.rows, other.col);
	 return matrix;
	 }
	
	 Matrix &Matrix::operator*=(const Matrix &other) {
	 *this = *this * other;
	 return *this;
	 }
	
	 Matrix Matrix::operator*(const Matrix &other) {
	 if (this->col != other.rows) {
	 throw invalid_argument("error");
	 }
	 vector<double> add_mat((unsigned long) (rows * other.col), 0);
	 for (unsigned long i = 0, m = 0; i < rows; ++i) {
	    for (unsigned long j = 0; j < other.col; ++j) {
	        double sum = 0;
	            for (unsigned long k = 0; k < col; ++k) {
	                sum += vector1[i * (unsigned long) (col) + k] *
	                other.vector1[k * (unsigned long) (other.col) + j];
	            }
	    add_mat.at(m++) = sum;
	    }
	 }
	 Matrix add{add_mat, rows, other.col};
	 return add;
	 }
	
	 Matrix &Matrix::operator*=(const double scalar) {
	 for (int i = 0; i < this->rows; i++) {
	    for (int j = 0; j < this->col; j++) {
	        this->vector1[(double) ((i * col) + j)] *= scalar;
	    }
	 }
	 return *this;
	 }
	
	// friend
	 ostream &operator<<(ostream &output, const Matrix &matrix) {
	 for (int i = 0; i < matrix.rows; ++i) {
	    output << "[";
	        for (int j = 0; j < matrix.col; ++j) {
	            output << matrix.vector1[(double) ((i * matrix.col) + j)];
	 
	            if (j < matrix.col - 1) {
	                output << " ";
	            }
	        }
	    output << "]";
	    if (i != (matrix.rows - 1)) { output << "\n";
      }
	 }
	 return output;
	 }
	
	 vector <string> Split_by_character(string will_split, char character) {
	 int length = will_split.length();
	 vector <string> ans;
	 string current;
	 for (int i = 0; i < length; i++) {
	    if (will_split[(unsigned long) i] == ' ') {
             break; 
        }
	 
	    if (will_split[(unsigned long) i] != ']' && will_split[(unsigned long) i] != '[') {
	        if (will_split[(unsigned long) i] == character) {
	         ans.push_back(current);
	        current = "";
	        }  
         else {
	     current += will_split[(unsigned long) i];
	     }
	   }
	 }
	 ans.push_back(current);
	 return ans;
	 }
	
	
	 istream &operator>>(istream &input, Matrix &matrix) {
	 string input_matrix;
	 char Input = '0';
	 vector <string> Columns;
	 vector <string> Rows;
	 vector<double> ans;
	
	 while (Input != '\n') {
	 Input = input.get();
	 
	 input_matrix += Input;
	 }
	 unsigned long size = input_matrix.length();
	 input_matrix.resize(size - 1); 
	
	 for (size_t j = 0; j < size - 2; j++) {
	    if (input_matrix.at(j) == ']') {
	        if (input_matrix.at(j + 1) != ',' || input_matrix.at(j + 2) != ' ') {throw invalid_argument("invalid argument");}}
	}
	 Rows = Split_by_character(input_matrix, ',');
	 for (size_t i = 0; i < Rows.size(); i++) {
	     Columns = Split_by_character(Rows[i], ' ');
	        for (size_t j = 0; j < Columns.size(); j++) {
	            ans.push_back(stod(Columns[j]));
	        }
     }
	 matrix.rows = Rows.size();
	 matrix.col = Columns.size();
	 matrix.vector1 = ans;
	 return input;
	 }
	}