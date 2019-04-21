# filler
Design an AI agent to compete in a 2D grid-filling game, in C using [minilibx](https://github.com/qst0/ft_libgfx). (42 Silicon Valley)

![screenshot](https://github.com/ashih42/filler/blob/master/Screenshots/ashih_vs_apuel.png)

The game engine `filler_vm` is provided.  The objectives are to implement:
* AI agent `ashih.filler`
* `visualizer`

## Game Rules
* Each turn, a player must place a new piece such that:
  * New piece overlaps with exactly 1 cell already occupied by the same player.
  * New piece ccupies all other empty cells.
* First player unable to place a new piece is the loser and will have no more turns.
* Game ends when both players cannot place a new piece.

## Prerequisites

You are on macOS with `gcc` and `make` installed.

## Compiling

```
make
```

## Running

Watch a fight between `ashih.filler` vs `apuel.filler`

```
./filler_vm -f maps/map01 -p1 players/ashih.filler -p2 players/apuel.filler
```

Watch a fight with `visualizer`

```
./filler_vm -f maps/map01 -p1 players/ashih.filler -p2 players/apuel.filler | ./visualizer
```

### Visualizer Controls
* `Right Arrow` Step forward turns *slowly*.
* `Left Arrow` Step backward turns *slowly*.
* `Up Arrow` Step forward turns *quickly*.
* `Down Arrow` Step backward turns *quickly*.
* `Spacebar` Reset to turn 0.
* `Escape` Terminate the visualizer.
