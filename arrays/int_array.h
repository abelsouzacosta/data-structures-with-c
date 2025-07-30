#ifndef INT_ARRAY

/**
 * @brief creates an malloced array with the size given as parameter
 *
 * @param size the size of the required array
 * @return malloced array with size
 */
int *create_int_array_with_size(int size);

/**
 * @brief insert the element given in the position provided
 *
 * @param element the element to be inserted
 * @param position position to insert the element
 * @param *array reference to the array
 */
int insert_element_at_position(int element, int position, int *array);
#endif // !INT_ARRAY
