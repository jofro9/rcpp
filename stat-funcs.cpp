#include <Rcpp.h>
#include <vector>
#include <iostream>

using namespace Rcpp;

// [[Rcpp::export]]              
double theSum(const std::vector<double>& Vec) {
    double sum = 0.;
    for ( double v : Vec ) {
        sum += v;
    }

    return sum;
}

// [[Rcpp::export]]              
double theMean(const std::vector<double>& Vec) {
    return theSum(Vec) / Vec.size();
}

// [[Rcpp::export]]              
double theVariance(const std::vector<double>& Vec) {
    const double& mean = theMean(Vec);
    double sum = 0.;
    
    for ( const double& v : Vec ) {
        sum += ((v - mean) * (v - mean));
    }
    
    return sum / (Vec.size() - 1);
}

// [[Rcpp::export]]
double theSD(const std::vector<double>& Vec) {
    return std::sqrt(theVariance(Vec));
}
