## Imagine You're Looking at a Big Shelf of Toys 🧸

Imagine you have a long row of colorful toys sitting on a shelf: a red car, a blue bear, a yellow duck, another red car, a green dinosaur, and so on.

A friend hands you a huge stack of cards asking questions like:

* *"How many different kinds of toys are between Toy #3 and Toy #10?"*
* *"How many different kinds of toys are between Toy #2 and Toy #8?"*
* *"How many different kinds of toys are between Toy #15 and Toy #20?"*

---

## 🐢 The Slow Way (Without Mo's Algorithm)

If you answer the cards in whatever random order they came in:

1. You put your left finger on Toy #3 and your right finger on Toy #10, count the toys, and write down the answer.
2. For the next card, you pick up both hands, run back to Toy #2 and Toy #8, and count everything all over again from scratch.
3. Then you run all the way down the shelf to Toy #15 and Toy #20.

By the end of the day, your feet hurt, you are exhausted, and you've spent almost all your time running back and forth!

---

## 🚀 The Smart Way: Mo's Algorithm

Mo's Algorithm is a clever trick that saves your energy. Instead of answering the questions in a chaotic order, you **reorder the question cards** so your fingers barely have to move!

Here is how the magic works:

### 1. Divide the Shelf into Small Blocks

Split the long shelf into small equal neighborhoods (in math terms, blocks of size $\sqrt{N}$).

### 2. Group the Question Cards

* Group all the cards based on **which neighborhood the left finger starts in**.
* If two cards start in the exact same neighborhood, arrange them so the **right finger only moves forward** (from left to right).

### 3. Slide Your Fingers Instead of Jumping 👈👉

Now, answer the cards in this new smart order:

* To get the answer for a new card, you don't start over! You just slide your left finger a step or two, and slide your right finger a step or two from where they already were.
* You just keep track of what toys you added or removed as your fingers slide.

Because you only make small adjustments from the *previous* question to answer the *next* question, you do almost zero wasted running.

---

> 💡 **The Big Takeaway:** > Mo's Algorithm turns a exhausting game of jumping back and forth into a smooth, easy stroll along the shelf by sorting all your questions **before** you start answering them!