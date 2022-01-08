#include "stdio.h"	// needed to compile csparse.h successfully
#include "csparse.h"
// These should be put in another tool file
/*
	Print vector
	how to seperate definition and declaration of template method: 
	http://www.cs.technion.ac.il/users/yechiel/c++-faq/separate-template-fn-defn-from-decl.html

	what does compilier do when coping with template method: 
	http://www.cs.technion.ac.il/users/yechiel/c++-faq/templates-defn-vs-decl.html
*/
template <typename elemType>
void tool_Print_vec(int length, elemType* array);

/*
	generate vec based on length
	Params:
		length: length of generated vector
		b:		generated double vector	
*/
void tool_Generate_Random_vec(int length, double* b);

/*
	complement the sparse coo to full coo
	sparse coo store only upper part. But CSparse library could only manipulate full part of coo.
	Params:
		cs:	coo format of CSparse.

*/
void tool_Complement_CS(cs* s);