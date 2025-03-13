Attempted to create a uninque pointer based linked list. Started as an experiment to see 
if it was possible. It is, I've already forgotten the things I learned, tho I do remember
it was necessary to remove some of the constructors. 
And the method 
```
std::ostream &operator<<(std::ostream &os, const std::unique_ptr<LinkedList> &list)
```
was tricky in that it was necessary to access the raw pointer to move along the list. 
It probably could have been done by transferring ownership. Introducing overhead maybe. 
If there was any intention to make the class thread safe this would be a weak point. 

Finally, trying to add an iterator for the list it became untenable. Considered creating an iterator class that is a singleton or a monostate. And realised this wouldnt be expected behaviour - that iterators can't keep track of different points in a list. 

So reverting the unique pointer idea as nothing more than an excercise in practicing converting raw pointers to smart