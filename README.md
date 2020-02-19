# push_swap

<img width="204" alt="Screenshot 2020-02-06 22 30 09" src="https://user-images.githubusercontent.com/44005264/74007222-71170200-4986-11ea-9758-529f5eedf207.png">


My solution for project **push_swap** in Hive Helsinki. Push_swap is a project that makes you sort data on a stack, with a limited set of instructions, using a lowest possible number of actions.\
Giving a list of unique intergers, the goal is to sort that list to ascending order, using two stacks (A and B) and following operations:

**sa**: swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.\
**sb**: swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.\
**ss**: **_sa_** and **_sb_** at the same time.\
**pa**: push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.\
**pb**: push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.\
**ra**: rotate a - shift up all elements of stack a by 1. The first element becomes the last one.\
**rb**: rotate b - shift up all elements of stack b by 1. The first element becomes the last one.\
**rr**: **_ra_** and **_rb_** at the same time.\
**rra**: reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.\
**rrb**: reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.\
**rrr**: ***rra*** and ***rrb*** at the same time.

The binary **push_swap** returns a list of operations which if performed on given array of integers makes it sorted.

The binary **checker** performs given commands on given array of integers. And returns **OK** if the stack A is sorted and stack B is empty, otherwise it returns **KO**.

You can check full subject's detail [here](https://github.com/shilena91/push_swap/blob/master/push_swap.en.pdf)

***

## The algorithm
I tried all sorting algorithm and realized that all of them worked, just giving different complexities. You can use different algorithm for different amount of intergers in order to give the least amount of commands, but the code would be much complex. I decided to use only one algorithm for this project, so my code could be clean and easy to modifiy in the future. In this case, quick-sort algorithm is the best choice.\
In my implementation, I reapeatly split stack A around medians, putting low numbers into stack B, and keep high numbers in stack A.

**Start**

Stack A: 1 7 9 4 10 3 2 11 25 30 (median = 9)\
Stack B:

**After split:**

Stack A: 11 25 30 10\
Stack B: 2 3 4 9 7 1

**Second split:**

Stack A: 11 25 30\
Stack B: 10 2 3 4 9 7 1

Once stack A was reduced to three or less numbers, it was sorted. Now I have 1 partition in stack A, I will set that as ```a->top```. I would then find median in stack B and push higher numbers back to stack A as next partition.

If three or less numbers were pushed back on to stack A, these numbers would be sorted using the swap and rotate commands, and a partition would be marked at the end of stack A too, signalling that stack A is sorted until this point. Stack B would then push onto A again as above.

If more than three numbers were pushed from B to A, stack A would then repeat the process at beginning, repeatedly splitting around a median of all the numbers after the last partition in A, maintaining the higher values and pushing the lower values onto B.

The whole above process would be repeated until stack A was sorted.

### Usage

Clone the repo as normal, go the clone folder in terminal:
> make

Above command create 2 binaries ```checker``` and ```push_swap```. Run those binaries with your list of intergers.

For example, with list "1, 4, 5, 0, 10, 9":
> ./checker 1 4 5 0 10 9\
> ./push_swap 1 4 5 0 10 9

```checker``` has option ```-v```. It shows status of 2 stacks after each command.

## Conclusion

It was nice project to learn sorting algorithim. I did not use recursion because imperative gives me better understanding of what's going on. In the future I could increase this project's performance by adding special treatment with special cases, such as different numbers of intergers.

