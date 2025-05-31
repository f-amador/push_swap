
![assets_task_01jwk4vcpzf3vbdztmn7b9txk3_1748694394_img_1](https://github.com/user-attachments/assets/a5b382b6-87c6-4bf3-8036-e2bb414c7494)


## 🎯 **Overview**  
*"Listen up! This project is about sorting numbers with two stacks - but not just any sorting! We're talking about maximum efficiency, minimum moves, and the power of the Best Friend Algorithm!"* 🔥  

Push_Swap is a **42 School** project where you sort numbers using two stacks (A and B) with a limited set of operations. *"And guess what? My Best Friend Algorithm makes it unstoppable!"* 💪  

---

## 🚀 **Features**  
- **Turbo-charged sorting** for both small (3-5) and large (100-500) datasets  
- **Best Friend Algorithm** *(because every number needs a buddy!)* 
- **Error handling** *"No weaklings allowed! Invalid inputs get rejected!"* ❌  
- **Optimized moves** *"Less moves = More power!"* ⚡  

---

## 🔥 **Installation**  
*"You wanna use this? Fine, here’s how!"*  

1. **Clone the repo:**  
   ```bash
   git clone git@github.com:f-amador/push_swap.git
   cd push_swap
   ```
2. **Compile it:** *(Don’t mess this up!)*  
   ```bash
   make
   ```

---

## 💥 **Usage**  
*"Here’s how you run it, but don’t waste my time with bad inputs!"*  

### Basic Usage:  
```bash
./push_swap 3 2 1 4
```
*"Want to test it? Pipe it into the checker!"*  
```bash
./push_swap 3 2 1 | ./checker 3 2 1
```
*"If it says ‘OK,’ you’re golden! If not… well, figure it out!"*  

---

## 🌀 **Operations**  
*"These are the moves—master them!"*  

| Command | Action |  
|---------|--------|  
| `sa`    | Swap top 2 in A |  
| `sb`    | Swap top 2 in B |  
| `ss`    | Swap both! |  
| `pa`    | Push from B to A |  
| `pb`    | Push from A to B |  
| `ra`    | Rotate A up |  
| `rb`    | Rotate B up |  
| `rr`    | Rotate both up! |  
| `rra`   | Reverse rotate A |  
| `rrb`   | Reverse rotate B |  
| `rrr`   | Reverse rotate both! |  

---

## 🤝 **The Best Friend Algorithm** *(Ao Todo’s Secret Technique!)*  
*"Every number in stack B needs a best friend in stack A—the smallest bigger number!"*  

### How it works:  
1. **Find Best Friends:**  
   - For each number in B, find its **closest bigger number** in A.  
   - If none exist, pair it with the **smallest number in A** *(because everyone needs a friend!)*  

2. **Optimized Pushing:**  
   - Calculate the **cheapest move** to reunite best friends.  
   - *"Efficiency is key! No wasted moves!"*  

### Code Highlight:  
```c
void ft_aoitodo(t_list **ahead, t_list **bhead) {
    t_list *bc = *bhead;
    while (bc) {
        long tmp = 214748364711; // "A ridiculously big number—just like my cursed energy!"
        t_list *ac = *ahead;
        while (ac) {
            long diff = ac->content - bc->content;
            if (diff > 0 && diff < tmp) {
                bc->bestfriend = ac; // "You two are best friends now!"
                tmp = diff;
            }
            ac = ac->next;
        }
        if (tmp == 214748364711) // "No best friend? Fine, take the smallest!"
            bc->bestfriend = ft_findsmallest(ahead);
        bc = bc->next;
    }
}
```

---

## 🏆 **Performance Goals**  
*"Anything less than perfection is unacceptable!"*  

| Numbers | Max Allowed Moves |  
|---------|------------------|  
| 3       | **3 or fewer** |  
| 5       | **12 or fewer** |  
| 100     | **~700** |  
| 500     | **~5500** |  

*"If you’re hitting these numbers, you’re doing great! If not… train harder!"*  

---

## ❌ **Error Handling**  
*"Mistakes? Not on my watch!"*  
- **Invalid numbers?** → *"Rejected!"*  
- **Duplicates?** → *"Absolutely not!"*  
- **Overflow?** → *"Get outta here!"*  

---

## 🧹 **Cleanup**  
*"Clean up after yourself!"*  
```bash
make fclean
```
