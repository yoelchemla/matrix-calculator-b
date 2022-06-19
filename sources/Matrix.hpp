#include <map>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
	
	namespace zich{
	    class Matrix{
	    private:
	        int rows;
	        int col;
	        std::vector<double> vector1;
	
	    public:
	   
	        Matrix(std::vector<double> MatrixVector, int rows, int col) {
	            if (rows <= 0 || col <= 0) {
	                throw invalid_argument("error");}
	            if (MatrixVector.size() != (rows * col)) {
	                throw invalid_argument("error");}
	            this->rows = rows;
	            this->col = col;
	            this->vector1=MatrixVector;
	        }
	
	        // Adding operators
	        Matrix operator+(Matrix const &other);
	        Matrix& operator+=(const Matrix &other);
	        friend Matrix operator+(Matrix &other);
	
	        // Subtraction operator
	        friend Matrix operator-(const Matrix &matrix1, const Matrix &matrix2);
	        Matrix& operator-=(const Matrix &other);
	        friend Matrix operator-(Matrix &other);
	        Matrix operator-(const Matrix &other);
	
	        // Comparison operator
	        bool operator>( Matrix &other);
	        bool operator>=( Matrix &other);
	        bool operator<( Matrix &other);
	        bool operator<=( Matrix &other);
	        bool operator==(const Matrix &other) const;
	        bool operator!=(const Matrix &other) ;
	
	        // Increasement operator
	        //++i
	        Matrix& operator++();
	        //i++
	        Matrix operator++(int);
	        //i--
	        Matrix operator--(int);
	        //--i
	        Matrix& operator--();
	
	        // Scalar doubling
	        friend Matrix operator*(const double scalar, Matrix &other);
	        friend Matrix operator*(Matrix &other, const double scalar);
	        Matrix& operator*=(const double scalar);
	
	        // Multiplication of two matrices
	        Matrix operator*(const Matrix &other);
	        Matrix& operator*=(const Matrix &other);
	
	      //friend
	        vector<string> Split_by_character(string will_split, char character);
	        friend ostream& operator<< (ostream& output, const Matrix &matrix);
	        friend istream& operator>> (istream& input, Matrix &matrix);
	    };
	}

	
