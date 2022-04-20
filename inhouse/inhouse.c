#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <stdio.h>

static PyObject *print_hello_world(PyObject *self) {
  printf("\nHello, World!\n");
  Py_RETURN_NONE;
}

int interval_counter(int start, int end) {
  int sum = 0;
  for (int i = start; i <= end; i++) sum += i;
  return sum;
}


static PyObject *interval_counter_wrapper(PyObject *self, PyObject *args) {
  int start, end;
  int sum;

  if (!PyArg_ParseTuple(args, "ii", &start, &end))
    return NULL;

  sum = interval_counter(start, end);

  return PyLong_FromLong(sum);
}


PyDoc_STRVAR(interval_counter_doc,
             "interval_counter(start, end, /)\n"
             "--\n\n"
             "Compute the sum of the integers in the interval [start, end].\n"
             "\n"
             "Args:\n"
             "    start (int): Start of the interval.\n"
             "    end (int): End of the interval.\n"
             "\n"
             "Returns:\n"
             "    sum (int): The sum of the integers in the interval: (end-start+1)(end+start)/2.\n"
             "\n"
             "Example:\n"
             "    >>> from mycounter import interval_counter\n"
             "    >>> interval_counter(2, 20)\n"
             "    >>> 209\n"
             );


static PyObject *list_append_1(PyObject *self, PyObject *args) {
  PyObject *pList;
  PyObject *temporary_item = NULL;
  if (!PyArg_ParseTuple(args, "O!", &PyList_Type, &pList)) {
    PyErr_SetString(PyExc_TypeError, "parameter must be a list.");
    return NULL;
  }

  temporary_item = PyLong_FromLong(1);
  PyList_Append(pList, temporary_item);
  Py_DECREF(temporary_item);
  temporary_item =  NULL; /* Good practice... */
  Py_RETURN_NONE;
}


static PyMethodDef InhouseMethods[] = {
  {"interval_counter", interval_counter_wrapper, METH_VARARGS, interval_counter_doc},
  {"print_hello_world", (PyCFunction)print_hello_world, METH_NOARGS, "Print hello world."},
  {"list_append_1", list_append_1, METH_VARARGS, "Happen 1 to a list."},
  {NULL, NULL, 0, NULL}        /* Sentinel */
};


static struct PyModuleDef inhouse_module = {
  PyModuleDef_HEAD_INIT,
  "inhouse",   /* Name of module */
  "Inhouse c python package",  /* Module documentation, may be NULL */
  -1,       /* Size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
  InhouseMethods
};


PyMODINIT_FUNC PyInit_inhouse(void) {
    return PyModule_Create(&inhouse_module);
}
