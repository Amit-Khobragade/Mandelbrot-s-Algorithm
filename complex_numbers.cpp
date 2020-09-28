#include "complex_numbers.h"

using namespace complex;


complex::complex_numbers::complex_numbers( double real_pt, double imaginary_pt )
	: realz{ real_pt }, imaginaryz{ imaginary_pt }
{
}


complex::complex_numbers::complex_numbers( const complex_numbers& other )
	: realz{ other.realz }, imaginaryz{ other.imaginaryz }
{
}


complex::complex_numbers::complex_numbers( complex_numbers&& other ) noexcept{
	this->imaginaryz = other.imaginaryz;
	this->realz = other.realz;
	other.imaginaryz = other.realz = 0;
}

complex_numbers& complex::complex_numbers::operator=( const complex_numbers& rhs ) {
	this->imaginaryz = rhs.imaginaryz;
	this->realz = rhs.realz;
	return *this;
}

complex_numbers& complex::complex_numbers::operator=( complex_numbers&& rhs )noexcept {
	this->imaginaryz = rhs.imaginaryz;
	this->realz = rhs.realz;
	rhs.realz = rhs.imaginaryz = 0;
	return *this;
}

//int* complex::conv_fraction( double number ) {
//	int precision{ 10000 };
//	int temp_num{ static_cast< int >(number * precision) };
//	while (true) {
//		if (precision % 2 == 0 && temp_num % 2 == 0) {
//			precision /= 2;
//			temp_num /= 2;
//		}
//		else if (precision % 5 == 0 && temp_num % 5 == 0) {
//			precision /= 5;
//			temp_num /= 5;
//		}
//		else
//			break;
//	}
//	int* num_and_denom{ nullptr };
//	num_and_denom = new int[2];
//	num_and_denom[0] = temp_num;
//	num_and_denom[1] = precision;
//	return num_and_denom;
//}

void complex::output_exponential( const complex_numbers& num ) {
	double theta{ arg_find( num ) };
	double r{ sqrt( num.realz + num.imaginaryz ) };
	std::cout << r << " x e^( i " << theta << " )";
}

complex_numbers complex::sin( const complex_numbers& num ) {
	double x{ num.realz }, y{ num.imaginaryz };
	double temp_realz = std::cosh( -y ) * std::cos( x );
	double temp_imaginaryz = std::sinh( -y ) * std::sin( x );
	return complex::complex_numbers( temp_realz, temp_imaginaryz );
}


complex_numbers complex::tan( const complex_numbers& num ) {
	double x{ num.realz }, y{ num.imaginaryz };
	complex_numbers temp_numerator{ (std::tan( x )),(-std::tanh( -y )) };
	complex_numbers temp_denominator{ 1, (std::tanh( -y ) * std::tan( x )) };
	return (temp_numerator / temp_denominator);
}

complex_numbers complex::cos( const complex_numbers& num ) {
	double x{ num.realz }, y{ num.imaginaryz };
	double temp_realz = std::cosh( -y ) * std::cos( x );
	double temp_imaginaryz = std::sinh( -y ) * std::sin( x );
	return complex_numbers( temp_realz, temp_imaginaryz );
}

complex_numbers complex::sinh( const complex_numbers& num ) {
	double x{ num.realz }, y{ num.imaginaryz };
	double temp_realz = std::sinh( x ) * std::cos( y );
	double temp_imaginaryz = std::cosh( x ) * std::sin( y );
	return complex_numbers( temp_realz, temp_imaginaryz );
}

complex_numbers complex::tanh( const complex_numbers& num ) {
	double x{ num.realz }, y{ num.imaginaryz };
	complex_numbers temp_numerator{ (std::tanh( x )), (std::tan( y )) };
	complex_numbers temp_denominator{ 1 , (std::tanh( x ) * std::tan( y )) };
	return (temp_numerator / temp_denominator);
}

complex_numbers complex::cosh( const complex_numbers& num ) {
	double x{ num.realz }, y{ num.imaginaryz };
	double temp_realz = std::cosh( x ) * std::cos( y );
	double temp_imaginaryz = std::sinh( x ) * std::sin( y );
	return complex_numbers( temp_realz, temp_imaginaryz );
}

//sinh^-1=ln(z+root(z^2+1))
complex_numbers complex::sinh_inverse( const complex_numbers& num ) {
	return (ln( num + pow( (pow( num, 2 ) + complex_numbers( 1, 0 )), 0.5 ) ));
}

//cosh^-1=ln(z+root(z+1)*root(z-1))
complex_numbers complex::cosh_inverse( const complex_numbers& num ) {
	return (ln( num + ((pow( (num + complex_numbers( 1, 0 )), 0.5 )) * (pow( (num + complex_numbers( -1, 0 )), 0.5 ))) ));
}

//tanh^-1=0.5*[ln(1 + z) - ln(1 - z)]
complex_numbers complex::tanh_inverse( const complex_numbers& num ) {
	return (0.5 * (ln( complex_numbers( 1, 0 ) + num ) - ln( complex_numbers( 1, 0 ) - num )));
}

complex_numbers complex::ln( const complex_numbers& num ) {
	double x{ num.realz };
	double y{ num.imaginaryz };
	return complex_numbers( (0.5 * std::log( std::pow( x, 2 ) + std::pow( y, 2 ) )), std::atan( x / y ) );
}


//z=(a+ib)^(x+iy)   taking log on both the sides
//log z = (x+iy)*ln(a+ib)
//=n+ic
//z=e^(n+ic)
complex_numbers complex::pow( const complex_numbers& num, complex_numbers& power ) {
	complex_numbers temp_final{ power * ln( num ) };
	temp_final = exp( temp_final );
	return temp_final;
}

complex_numbers complex::exp( const complex_numbers& num ) {
	double x{ num.realz };
	double y{ num.imaginaryz };
	return complex_numbers( std::exp( x ) * std::cos( y ), std::exp( x ) * std::sin( y ) );
}


complex_numbers complex::operator+( const complex_numbers& first, const complex_numbers& second ) {
	complex_numbers temp;
	temp.realz = first.realz + second.realz;
	temp.imaginaryz = first.imaginaryz + second.imaginaryz;
	return temp;
}


complex_numbers complex::operator-( const complex_numbers& first, const complex_numbers& second ) {
	complex_numbers temp;
	temp.realz = first.realz - second.realz;
	temp.imaginaryz = first.imaginaryz - second.imaginaryz;
	return temp;
}


bool complex::operator==( const complex_numbers& lhs, const complex_numbers& rhs ) {
	return ((lhs.realz == rhs.realz) && (lhs.imaginaryz == rhs.imaginaryz));
}


bool complex::operator!=( const complex_numbers& lhs, const complex_numbers& rhs ) {
	return (!(lhs == rhs));
}


//(realz3+imaginary3)=(realz1+i*imaginaryz1)*(realz2+i*imaginaryz2)
//(realz3+imaginary3)=((realz1*realz2)-(imaginary1*imaginary2))+i*((realz1*imaginaryz2)+(realz2*imaginaryz1))
//realz3=(realz1*realz2)-(imaginary1*imaginary2)
//imaginaryz3=(realz1*imaginaryz2)+(realz2*imaginaryz1)
complex_numbers complex::operator*( const complex_numbers& first, const complex_numbers& second ) {
	double temp_realz{ 0 }, temp_imaginaryz{ 0 };
	temp_realz = (first.realz * second.realz) - (first.imaginaryz * second.imaginaryz);
	temp_imaginaryz = (first.realz * second.imaginaryz) + (first.imaginaryz * second.realz);
	return complex_numbers( temp_realz, temp_imaginaryz );
}

//stream insertion
std::ostream& complex::operator<<( std::ostream& os, const complex::complex_numbers& num ) {
	os << std::setprecision( 2 ) << std::fixed
		<< num.realz << std::showpos << " " << num.imaginaryz << " i"
		<< std::resetiosflags( std::ios::fixed | std::ios::showpos )
		<< std::setprecision( 6 );
	return os;
}


//stream extraction
std::istream& complex::operator>>( std::istream& is,  complex::complex_numbers& num ) {
	
	std::cout << "enter the complex number (a+ib): ";
	std::string temp_unformatted, temp_formatted;
	do {
		std::getline( is, temp_unformatted );
	}
	while (temp_unformatted == "" || temp_unformatted == "\n");

	for (char a : temp_unformatted) {
		if (a == '+' || a == '-') 
			temp_formatted = temp_formatted + "\n" + a;
		else if(a==' '){}  //do nothing as no spaces are required
		
		else 
			temp_formatted = temp_formatted + a;
	}
	std::stringstream ss{ temp_formatted };
	std::string part1, part2{"0.0i"};
	do {
		ss >> part1;
	}
	while (part1 == "" || part1 == "\n");
	do {
		ss >> part2;
	}
	while (part2 == "" || part2 == "\n");

	bool found1{ part1.find( "i" ) != std::string::npos };
	bool found2{ part2.find( "i" ) != std::string::npos };
	if (found1)
		part1.erase( part1.find( "i" ), 1 );
	if(found2)
		part2.erase( part2.find( "i" ), 1 );
	double temp_img1, temp_img2;
	ss = std::stringstream( part1 );
	ss >> temp_img1;
	ss = std::stringstream( part2 );
	ss >> temp_img2;

	if (found1 && !found2) {
		num.imaginaryz = temp_img1;
		num.realz = temp_img2;
	}
	else if (!found1 && found2) {
		num.imaginaryz = temp_img2;
		num.realz = temp_img1;
	}
	else if (found1 && found2)
		num.imaginaryz = temp_img1 + temp_img2;
	
	else if (!found1 && !found2)
		num.realz = temp_img1 + temp_img2;
	
	else
		std::cout << "sorry wrong input";

	return is;
}


//first/second=(a+ib)/(x+iy)
//(first*conjugate(second))/second*conjugate(second)=(a+ib)*(x-iy)/(x+iy)*(x-iy)
//(first*conjugate(second))/real number=(a+ib)*(x-iy)/(x^2+y^2)
complex_numbers complex::operator/( const complex_numbers& first, const complex_numbers& second ) {
	complex_numbers numerator, denominator;
	numerator = first * conjugate( second );
	denominator = second * conjugate( second );
	double temp_second_real{ real_part( denominator ) };
	return (numerator / temp_second_real);
}

complex_numbers complex::conjugate( complex_numbers num ) {
	num.imaginaryz = (-num.imaginaryz);
	return num;
}

double complex::real_part( const complex_numbers& num ) {
	return num.realz;
}

double complex::imaginary_part( const complex_numbers& num ) {
	return num.imaginaryz;
}

double complex::arg_find( const complex_numbers& num ) {
	double result{ atan( num.imaginaryz / num.realz ) };
	result *= 180;
	result /= 3.1415927;
	return result;
}

