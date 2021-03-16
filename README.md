PRINTF

This repository is the home to a printf mimic written by Justin Masayda (@keysmusician) and Nels Fichera. 
The dev_printf file found in the dev branch shows work which has yet to be perfected, and is still in development. 
The printf file found in the main branch reflects fully functional options for the mimic program. 

Created while at Holberton School, this git mimic only makes use of write, malloc, free, va_start, va_end, va_copy, and va_arg from the standard library. All other functionality is proprietary. 

Printf flags which manipulate text can be found in text.c. 
Printf flags which manipulate numbers can be found in numbers.c
See man_3_printf for more information regarding which flags are currently supported. 
See holberton.h for prototypes. 

This function works on the assumption that we are passing character pointers, so there is minimal calls to write, and support functions only do formatting, they do not interfere with the buffer or output functions. The printf main function is used primarily to parse until a flag is found. The buffer is a simple character array, which is emptied when full, and prints from the last empty location. This ensures that memory is used efficiently. As always, comments and questions are welcome! Please get in touch with us! 

NF, JM.
