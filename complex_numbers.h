#pragma once
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>

namespace complex { class complex_numbers; }


namespace complex {
	std::ostream& operator<<( std::ostream& os, const complex_numbers& num );
	std::istream& operator>>( std::istream& is, complex_numbers& num );

	class complex_numbers {
	private:
		double realz;
		double imaginaryz;
	public:
		complex_numbers( double real_pt = 0.0, double imaginary_pt = 0.0 );
		complex_numbers( const complex_numbers& other );
		complex_numbers( complex_numbers&& other )noexcept;
		friend complex_numbers operator+( const complex_numbers& first, const complex_numbers& second );
		friend complex_numbers operator-( const complex_numbers& first, const complex_numbers& second );
		friend bool operator==( const complex_numbers& lhs, const complex_numbers& rhs );
		friend bool operator!=( const complex_numbers& lhs, const complex_numbers& rhs );
		friend complex_numbers operator*( const complex_numbers& first, const complex_numbers& second );
		template<typename t>
		friend complex_numbers operator*( t first, const complex_numbers& second );
		template<typename t>
		friend complex_numbers operator*( const complex_numbers& first, t second );
		friend std::ostream& operator<<( std::ostream& os, const complex_numbers& num );
		friend std::istream& operator>>( std::istream& is, complex_numbers& num );
		friend complex_numbers operator/( const complex_numbers& first, const complex_numbers& second );
		template<typename t>
		friend complex_numbers operator/( const complex_numbers& first, t second );
		template<typename t>
		friend complex_numbers operator/( t first, const complex_numbers& second );
		complex_numbers& operator=( const complex_numbers& rhs );
		complex_numbers& operator=( complex_numbers&& rhs )noexcept;
		friend complex_numbers conjugate( complex_numbers num );
		friend double real_part( const complex_numbers& num );
		friend double imaginary_part( const complex_numbers& num );
		friend double arg_find( const complex_numbers& num );
		template<typename T>
		friend complex_numbers pow( const complex_numbers& num, T power );
		//friend int* conv_fraction( double fractional_pt );
		friend void output_exponential( const complex_numbers& num );
		friend complex_numbers sin( const complex_numbers& num );
		friend complex_numbers tan( const complex_numbers& num );
		friend complex_numbers cos( const complex_numbers& num );
		friend complex_numbers sinh( const complex_numbers& num );
		friend complex_numbers tanh( const complex_numbers& num );
		friend complex_numbers cosh( const complex_numbers& num );
		friend complex_numbers sinh_inverse( const complex_numbers& num );
		friend complex_numbers cosh_inverse( const complex_numbers& num );
		friend complex_numbers tanh_inverse( const complex_numbers& num );
		friend complex_numbers ln( const complex_numbers& num );
		friend complex_numbers pow( const complex_numbers& num, complex_numbers& power );
		friend complex_numbers exp( const complex_numbers& num );
		friend inline double mod( const complex_numbers& num ) {
			double x2 = num.realz * num.realz;
			double y2 = num.imaginaryz * num.imaginaryz;
			double modulus = sqrt( (x2 + y2) );
			return(modulus);
		}
		friend inline double mod_sq( const complex_numbers& num ) {
			double x2 = num.realz * num.realz;
			double y2 = num.imaginaryz * num.imaginaryz;
			return (x2 + y2);
		}
	};
	template<typename t>
	complex_numbers operator*( t first, const complex_numbers& second ) {
		double temp_realz{ 0 }, temp_imaginaryz{ 0 };
		temp_realz = first * second.realz;
		temp_imaginaryz = first * second.imaginaryz;
		return complex_numbers( temp_realz, temp_imaginaryz );
	}
	template<typename t>
	complex_numbers operator*( const complex_numbers& first, t second ) {
		return (second * first);
	}
	template<typename t>
	complex_numbers operator/( const complex_numbers& first, t second ) {
		double temp_realz, temp_imaginaryz;
		temp_realz = first.realz / second;
		temp_imaginaryz = first.imaginaryz / second;
		return complex_numbers( temp_realz, temp_imaginaryz );
	}
	template<typename t>
	complex_numbers operator/( t first, const complex_numbers& second ) {
		return (complex_numbers( first, 0 ) / second);
	}
	//z=(x+iy)^n=r*(cos (n*theta)+ i sin(n*theta))
	//using demoiver's theorm
	template<typename T>
	complex_numbers pow( const complex_numbers& num, T power ) {
		double theta{ arg_find( num ) };
		double r_n{ std::pow( sqrt( num.realz + num.imaginaryz ),power ) };
		double temp_realz{ r_n * cos( power * theta ) };
		double temp_imaginaryz{ r_n * sin( power * theta ) };
		return complex_numbers( temp_realz, temp_imaginaryz );
	}
}
