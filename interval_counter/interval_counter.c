#define PY_SSIZE_T_CLEAN
#include <Python.h>


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


static PyMethodDef CounterMethods[] = {
  {"interval_counter",  interval_counter_wrapper, METH_VARARGS, interval_counter_doc},
  {NULL, NULL, 0, NULL}        /* Sentinel */
};


static struct PyModuleDef mycounter_module = {
  PyModuleDef_HEAD_INIT,
  "mycounter",   /* Name of module */
  "Inhouse c python package",  /* Module documentation, may be NULL */
  -1,       /* Size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
  CounterMethods
};


PyMODINIT_FUNC PyInit_mycounter(void) {
    return PyModule_Create(&mycounter_module);
}
