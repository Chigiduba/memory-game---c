# memory-game---c
An attempt to play memory with c

1. To play memory, we need a random shuffle of a set of cards, and that's what the shuffle function does. It takes the level specified in
createGame function and it uses its double, so that we have an even number of cards.
The idea is to shuffle an array of (level*2) elements (i.e. given n = 2*level, we assign to each element of the array a random value
between 0 and n, and we do that without repetition ).
2. In function generateGame, we take the generated array from shuffle function, we iterate sequentialy through it and we use the values
stored in its elements (which will be randomly generated from shuffle) as indexes for where the letters should be stored. We assign two
letters at a time in order to get pairs of letters assigned to two randomly generated positions.
