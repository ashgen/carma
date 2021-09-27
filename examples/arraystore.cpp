#include "arraystore.h"

/* This is an example of a class where the data is stored
 * in C++. An example use-cae would be a regression where
 * you only return the underlying arrays when requested.
 *
 * Additional functionality exists for setting data directly
 * from a arma::vec or retrieving the matrix.
 */

class ExampleClass {
    private:
        arma::vec _x;
        arma::vec _y;

    public:
        ExampleClass(arma::vec & x,arma::vec & y) :
        _x(x),_y(y) {}

        arma::vec member_func() {
            // normallly you would something useful here
            _x += _y;
            // return mutable view off arma matrix
            return _x;
        }
};

void bind_exampleclass(py::module &m) {
    py::class_<ExampleClass>(m, "ExampleClass")
        .def(py::init<arma::vec &,arma::vec &>(), R"pbdoc(
            Initialise ExampleClass.

            Parameters
            ----------
            arr1: np.ndarray
                array to be stored in armadillo matrix
            arr2: np.ndarray
                array to be stored in armadillo matrix
        )pbdoc")
        .def("member_func", &ExampleClass::member_func, R"pbdoc(
            Compute ....
        )pbdoc");
}
