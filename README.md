# Get Next Line

<div>

  ![Project](https://img.shields.io/badge/Project-Libft-blue)
  ![Licence](https://img.shields.io/badge/Licence-MIT-orange)
  ![Version](https://img.shields.io/badge/Version-1.0-green)
  <a href="https://github.com/MiMendiola/Get_Next_Line/tree/main/Documentation/README.es.md" >
    <img src="https://img.shields.io/badge/Cambiar_Idioma-Español-purple" align="right">
  </a>

</div>

The aim of this project is to create a very practical function that we can use later and to learn the concept of `static variables` in C.

We will also start dealing with `file descriptors (fd)` and learn how they work and how we can traverse them independently of the characters we can read, ending by reading the entire file. In my solution, we will learn to manage and benefit from `pointer references` to use the memory of our strings directly.

We need to deliver 3 files, and each one must have specific information for each with a maximum of 5 functions per file.

These functions should be in our `utils` file. In my case, I used functions from the libft project, but these functions are modified, and I used `ft_strlen`, `ft_strchr`, `ft_strjoin`, and `ft_substr`.

In our `get_next_line.h` file, we will have to add all the `function prototypes` used. Additionally, we will include the `libraries` we need and `define a BUFFER_SIZE` so that we can choose the size of the characters we will read manually when compiling the file. If no value is given, it will be executed directly with the size we have defined in our file.

We continue with our most important file, `get_next_line.c`, in which we will have, in my case, 4 functions.

- **void    free_all(char** ****to_free):** We will `clean from the pointer reference` passed as a parameter and set the `pointer to NULL` to avoid errors.

- **char	*get_next_line(int fd)**: We will have our `static variable` and the variable that will hold our `line to display`. We will check that nothing we use gives an error and run our other functions there, returning the variable we need to print.

- **char**	***read_till_find(int fd, char** ***str_static):** As parameters, we will have our `static` and the `fd`. We will create a `variable that will contain the read bytes` and a `str with the size of BUFFER_SIZE + 1`, check that the `'\n’` is not in the buffer's reading, and that the `byte reading is different from zero`. We will check that if `bytes < 0`, there will be an error, and we will clean the static, returning NULL. If `bytes == 0`, we will exit the loop to return our read line.
    
    We will continue by adding the `\0 to our line` and adding to our static the entire line read, and we finish by `returning our static` with everything read.
    
- **void relocate_line(char** ****str_static, char** ****front):** As parameters, we will have our `reference to static` and `reference to line to print`. With this, we can modify directly from the memory of our pointers and modify them in the same function. We will check that our static is not NULL and that it exists. If not, we will initialize it to NULL. Then we will look for the first line until we find `\0 or \n`, and we will continue adding 1 more position to our iterator to get the newline or null.
    
    Knowing this, we can get the first line by applying `ft_substr` to `*front` from the first position to the size we find. We will continue saying that `back` will be equal to the memory address of the static to be able to `freeze it`. We continue by applying `ft_substr` to `*static` from when we find the newline until the `total length - the newline encounter`. This will create a new memory address for our static with the new necessary information, and we are free to freeze our back.
    

---

## Table of Contents

[GET_NEXT_LINE.C](./get_next_line.c)

[GET_NEXT_LINE_UTILS.C](./get_next_line_utils.c)

[GET_NEXT_LINE.H](./get_next_line.h)

[BONUS](./bonus/)

---

## Recommendations

We can use functions that we have previously created in one of our previous project `Libft`, or we could also recreate them according to our needs.

Use the VSC compiler, which will help review that our variable creations are done cleanly and without any problems, and it will help us understand our code much better.

Before starting, we should be clear if we want to do it with the bonus part or not. In case of wanting to do it with bonuses, we should be clear about these 2 conditions:

- Develop get_next_line() with a single static variable.
- Your get_next_line must be capable of managing multiple file descriptors at once, potentially in an alternating manner, without losing the reading thread of each file descriptor.

Also, we must add `_bonus` in the bonus files.

Another thing to consider is that we need to be observant and know where we will have to `free`, and we will do this every time we reserve memory in our program.

---

## Contact

If you have any questions, suggestions, or comments about Get_Next_Line, feel free to contact me:

- Email: <a href="mailto:mglmendiol@gmail.com" style="text-decoration: none; color:#fff">mglmendiol@gmail.com</a>
- LinkedIn: <a href="https://www.linkedin.com/in/mimendiola/" style="text-decoration: none; color:#fff !important;">https://www.linkedin.com/in/mimendiola/</a>
