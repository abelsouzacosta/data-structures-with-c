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

/**
 * @brief removes an element of the position given
 *
 * @param position position to remove the element
 * @param *array reference to the array
 */
int remove_element_from_position(int position, int *array);

/**
 * @brief replaces the element in the array given at the given position
 *
 * @param new_element the element that will replace the current
 * @param position the position of the element
 * @param *array reference to the array
 */
int replace_element_in_position(int new_element, int position, int *array);

/**
 * @brief resize the array given to the new size
 *
 * @param *array reference to the array
 * @param new_size the new size of the array given
 */
int resize_array(int *array, int new_size);

#endif // !INT_ARRAY
