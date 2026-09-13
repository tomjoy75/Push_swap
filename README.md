# push_swap

Sort a stack of integers using a second stack and a restricted instruction set, in as few
operations as possible. A 42 project.

The program prints the operations; it does not print the sorted stack. Correctness is checked
by replaying that output through a checker.

## The instruction set

Eleven operations, and no others:

| | |
|---|---|
| `sa` `sb` `ss` | swap the first two elements of `a`, of `b`, or of both |
| `pa` `pb` | move the top element from one stack to the other |
| `ra` `rb` `rr` | rotate up — the first element becomes the last |
| `rra` `rrb` `rrr` | rotate down — the last element becomes the first |

`ss`, `rr` and `rrr` act on **both stacks at once and cost one operation instead of two**.
That single fact shapes the whole solution.

## Approach

**Index, don't compare.** Values are normalised to their rank once, up front. After that the
algorithm never compares input values again — it compares indices, which makes every later
cost calculation exact rather than approximate.

**Push in chunks.** `a` is emptied into `b` in slices of the index range rather than element by
element. Each element crossing over is pushed with `pb`; if its index falls in the lower part
of the current slice it is rotated down immediately, so `b` ends up roughly ordered rather
than arbitrary. The number of slices is derived from the input size.

**Bring back by cost, not by position.** Every node in `b` carries its rotation cost to the
top (`r`), its cost the other way (`rr`), and a pointer to the node in `a` it must land above.
Four strategies are evaluated per candidate — rotate both up, rotate both down, or either one
of the mixed pairs — and the cheapest is executed. Where both stacks turn the same way, the
combined `rr` / `rrr` are used, which is where the savings come from.

## Measured

Five random permutations per size, on this implementation:

| n | mean operations | worst seen |
|---|---|---|
| 3 | 1 | 1 |
| 5 | 10 | 12 |
| 100 | **573** | 603 |
| 500 | **4,246** | 4,359 |

Both sizes land in the subject's top band — under 700 at 100, under 5,500 at 500.

Reproduce it:

```sh
make
ARG=$(python3 -c "import random;v=list(range(1,101));random.shuffle(v);print(' '.join(map(str,v)))")
./push_swap $ARG | wc -l
```

## Building and running

```sh
make          # push_swap
make bonus    # checker
./push_swap 3 1 5 2 4
```

Arguments may be passed as separate integers or as a single quoted string. Duplicates,
non-integers and values outside `int` are rejected with `Error` on stderr.

## Layout

```
srcs/
  parsing.c indexation.c            # argument handling, rank normalisation
  stack_pre_sort.c                  # the chunked push into b
  counting.c algo_utils.c           # rotation costs and cheapest-move selection
  stack_final_sort.c                # the cost-driven return to a
  push.c swap.c rotate.c rev_rotate.c
  data_structure.c memory.c
libft/                              # own C library
```

## Seeing it run

The operation list is text, which is hard to read at a hundred elements. Third-party
visualisers replay that output as an animation — they take the program's stdout and draw it.
Worth knowing they exist; none of that code is mine, and only the algorithm here is.
