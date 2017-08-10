# tic_tac_toe
My understanding of machine learning, while very limited, is as follows:

1. Identify a problem. The problem *must* be one where a single decision must be made from multiple otherwise identical options.
2. Determine every factor that influences the decision when made by a human.
3. Simplify this problem into a single function, with the determined factors as parameters.
That is, an operation that produces the same output for given input.
4. Break the human decision process for this problem into discrete steps, which are executed in sequence.
5. For each step, create a function, which produces an output that will be passed to the next function.

If your algorithm is stateless, then it should be relatively simple to store the results of a decision,
as well as the provided inputs in a metadata file. If you provide your program a way to read this metadata,
then it can effectively *remember* which inputs produce desired outputs.

I have no real idea how neural networks, and mostly don't understand what they are. I just started
the Andrew Ng course last night, which hopefully will clear it up. But I assume it's probably something
similar to what I outlined above, though definitely more refined.

Anyways, this brings us to the actual *learning*. We've determined the *task*, which is the act of solving our problem.
In this case, this would be making a single tic-tac-toe move.

The measure of *performance* would be whether the move eventually leads to a win.

Once we have written a simple AI that can choose a move, it becomes a matter of training it.
Tic-tac-toe is very simple to write an AI for, so let's make it a little difficult: the algorithm
you write should *only* be written to know how to choose an open space. It shouldn't be written to
choose winning moves by default. It needs to learn that.

---