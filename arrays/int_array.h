#ifndef INT_ARRAY
#define INT_ARRAY

/**
 * @brief creates an malloced array with the size given as parameter
 *
 * @param size the size of the required array
 * @return malloced array with size
 */
int *create_int_array_with_size(int size);

/**
 * @brief removes an element of the position given
 *
 * @param position position to remove the element
 * @param size the size of the array
 * @param *array reference to the array
 */
int *remove_element_at_position(int position, int size, int *array);

#endif // !INT_ARRAY
