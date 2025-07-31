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

/**
 * @brief inserts an element at the first position
 *
 * Resizes the original array with realloc
 * then shift the elements to the right
 * and then insert the element provided in the first position
 *
 * @param element the element to be inserted
 * @param size the original size of the array
 * @param *array the reference to the array
 */
int *insert_first_position(int element, int size, int *array);

/**
 * @brief removes the element of the last position given
 *
 * Uses realloc to shrink the original array
 *
 * @param *array the reference to the array
 * @param size the original size of the array
 */
int *remove_from_last_position(int *array, int size);

/**
 * @brief insert a element in the last position
 *
 * Uses realloc to stretch the array and the inserts a new element there
 *
 * @param *array the reference to the array
 * @param size the size of the original array
 * @param element the new element to be inserted at the end of the array
 */
int insert_at_last_position(int *array, int size, int element);

#endif // !INT_ARRAY
