#include <Python.h>

/* Define the function that adds two numbers. */
static PyObject *add(PyObject *self, PyObject *args) {
  int a, b;

  /* Check the number of arguments. */
  if (!PyArg_ParseTuple(args, "ii", &a, &b)) {
    return NULL;
  }

  /* Add the two numbers and return the result. */
  return Py_BuildValue("i", a + b);
}

/* Define the module's methods. */
static PyMethodDef methods[] = {
  {"add", add, METH_VARARGS, "Add two numbers."},
  {NULL, NULL, 0, NULL}
};

/* Define the module. */
static struct PyModuleDef moduledef = {
  PyModuleDef_HEAD_INIT,
  "my_library",
  "A simple library that adds two numbers.",
  -1,
  methods
};

/* Initialize the module. */
PyMODINIT_FUNC PyInit_my_library(void) {
  return PyModule_Create(&moduledef);
}
