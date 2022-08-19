#include <Python.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>
#include <fstream>
#include <algorithm>
#include "Groceries.h"

using namespace std;

int Groceries::callIntFunc(string proc, int param) {
	{
		char* procname = new char[proc.length() + 1];
		std::strcpy(procname, proc.c_str());

		PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
		
		Py_Initialize(); // Initialize the Python Interpreter
		
		pName = PyUnicode_FromString((char*)"PythonCode"); // Build the name object
		
		pModule = PyImport_Import(pName); // Load the module object
		
		pDict = PyModule_GetDict(pModule); // pDict is a borrowed reference 
		
		pFunc = PyDict_GetItemString(pDict, procname); // pFunc is also a borrowed reference 

		if (PyCallable_Check(pFunc))
		{
			pValue = Py_BuildValue("(i)", param);
			PyErr_Print();
			presult = PyObject_CallObject(pFunc, pValue);
			PyErr_Print();
		}

		else
		{
			PyErr_Print();
		}

		Py_DECREF(pValue);
		// Clean up
		Py_DECREF(pModule);
		Py_DECREF(pName);
		// Finish the Python Interpreter
		Py_Finalize();

		// clean 
		delete[] procname;

		return _PyLong_AsInt(presult);
	}
}

int Groceries::callIntFunc(string proc, string param) {
	{
		char* procname = new char[proc.length() + 1];
		std::strcpy(procname, proc.c_str());

		char* paramval = new char[param.length() + 1];
		std::strcpy(paramval, param.c_str());


		PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
		
		Py_Initialize(); // Initialize the Python Interpreter
		
		pName = PyUnicode_FromString((char*)"PythonCode"); // Build the name object
		
		pModule = PyImport_Import(pName); // Load the module object
		
		pDict = PyModule_GetDict(pModule); // pDict is a borrowed reference 
		
		pFunc = PyDict_GetItemString(pDict, procname); // pFunc is also a borrowed reference 

		if (PyCallable_Check(pFunc))
		{
			pValue = Py_BuildValue("(z)", paramval);
			PyErr_Print();
			presult = PyObject_CallObject(pFunc, pValue);
			PyErr_Print();
		}

		else
		{
			PyErr_Print();
		}
		
		Py_DECREF(pValue);
		// Clean up
		Py_DECREF(pModule);
		Py_DECREF(pName);
		// Finish the Python Interpreter
		Py_Finalize();

		// clean 
		delete[] procname;
		delete[] paramval;


		return _PyLong_AsInt(presult);
	}
}

void Groceries::CallProcedure(string pName) {
	{
		char* procname = new char[pName.length() + 1];
		std::strcpy(procname, pName.c_str());

		Py_Initialize();
		PyObject* my_module = PyImport_ImportModule("PythonCode");
		PyErr_Print();
		PyObject* my_function = PyObject_GetAttrString(my_module, procname);
		PyObject* my_result = PyObject_CallObject(my_function, NULL);
		Py_Finalize();

		delete[] procname;
	}

}