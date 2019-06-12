# HashMap

HashMap <class K, class V, class F>

Implement a template class for HashMap (type for keys, type for values, dispersion function). In case of collision, 
the HashMap will store the values in a linked list. The Class should have the following features:

	- Constructor without parameters which initiates and empty HashMap
	- Copy constructor and asignment operator
	- Function for adding, searching and deleting an element in the HashMap
	- Function for obtaining the number of different keys in the HashMap
	- Function that returns a vector (STL) containing the values for a known key
	- Overload for operator [] (returns the first known value for a certain key)
	- Overload for the output operator