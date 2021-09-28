#include "arraystore.h"
#include "../../bsplines/bsplines.hpp"


class bspline :public bspline_basis{
    
    public:
        bspline(arma::vec & x,int degree) :
        bspline_basis(arma::conv_to<std::vector<double>>::from(x),degree) {}

        arma::mat basis(const arma::vec test){
           return basis_matrix(test); 
        }
};

void bind_exampleclass(py::module &m) {
    py::class_<bspline>(m, "bspline")
        .def(py::init<arma::vec &,int >(), R"pbdoc(
            Initialise bspline Example class.
            arr1:knots 
            arr2:degree
        )pbdoc")
        .def("basis", &bspline::basis, R"pbdoc(
            Compute basis matrix
        )pbdoc");
}
