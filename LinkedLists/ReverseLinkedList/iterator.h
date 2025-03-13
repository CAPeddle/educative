        /**
         * u/brief Permits the list to be traversed using a independent iterator that looks one node at a time.
         * @remarks std::iterator is deprecated, instead it works now with concepts, so we have to "just point into the
         *    right direction" and the compiler understands the intention behind it.
         * @see https://en.cppreference.com/w/cpp/iterator/iterator
         * @see https://en.cppreference.com/w/cpp/language/constraints
         */
#include <iterator>
        class iterator
        {
            friend class LinkedList;

            public:
                ///The category of the iterator, one of https://en.cppreference.com/w/cpp/iterator/iterator_tags
                using iterator_category = std::forward_iterator_tag;
                using difference_type   = std::ptrdiff_t; ///<How to identify distance between iterators.
                using value_type        = T; ///<The dereferenced iterator type.
                using pointer           = T*; ///<Defines a pointer the iterator data type.
                using reference         = T&; ///<Defines a reference the iterator data type.

            private:
                LinkedList::node_s *_readhead = nullptr; //current node being read
                LinkedList::node_s *_aux_node = nullptr; //keeps track of previous node, required for remove!

            public:
                /** @brief Default Constructor. */
                iterator () { }
                /** @brief Constructor.
                 * @param head- reference to the beginning of the list. */
                iterator (LinkedList::node_s &head);

                // reference operator*() const;

                // pointer operator->();

                /** @brief Increments the iterator position to the next node. */
                iterator& operator++();

                /** @brief Reads the iterator contents and than increments the iterator position to the next node. */
                iterator& operator++(int);

                /** @brief Compares the contents of two iterators (not the package value!).
                 * @return <b>true</b> if the two nodes are equal; <b>false</b> if different. */
                bool operator== (iterator &other) const {return this->_readhead == other._readhead;}

                /** @brief Compares the contents of two iterators (not the package value!).
                 * @return <b>true</b> if the two nodes are different; <b>false</b> if equal. */
                bool operator!= (iterator &other) const;
        };//end class Iterator