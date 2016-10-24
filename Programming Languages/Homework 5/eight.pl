# Write a Perl program that uses a hash and a large number of operations on
# the hash. For example, the hash could store people’s names and their ages.
# A random-number generator could be used to create three-character names and
# ages, which could be added to the hash. When a duplicate name was generated,
# it would cause an access to the hash but not add a new element. Rewrite the
# same program without using hashes. Compare the execution efficiency of the
# two. Compare the ease of programming and readability of the two.


#!/usr/bin/perl

@alphabet = ("a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p",
"q","r","s","t","u","v","w","x","y","z");

# -------------------- Hash Method --------------------

$start = time;
for ($i = 0; $i < 100; $i++) {
    # Create 3-name variable
    for ($j = 0; $j < 3; $j++) {
        $char = $alphabet[rand(26)];
        $nameArray[$j] = $char;
        # print ("Character: ", $char, "\n");
    }

    # Turn name into a string
    $name = $nameArray[0] . $nameArray[1] . $nameArray[2];

    # Create age
    $age = int(rand(120));

    # Assign both to hash
    $data{$name} = $age;
}
$duration = time - $start;
print ("Hash execution time: ", $duration, "s \n");

# print "$_\n" for keys %data;


# -------------------- Array Method --------------------

@array;
$start = time;
for ($i = 0; $i < 100; $i++) {
    # Create 3-name variable
    for ($j = 0; $j < 3; $j++) {
        $char = $alphabet[rand(26)];
        $nameArray[$j] = $char;
        # print ("Character: ", $char, "\n");
    }

    # Turn name into a string
    $name = $nameArray[0] . $nameArray[1] . $nameArray[2];

    # Create age
    $age = int(rand(120));

    # Check to see name is inside array
    $flag = 0;
    for ($k = 0; $k < $i; $k++) {
        if ($array[$k][0] == $name) {
            $flag = 1;
            break;
        }
    }

    # Add to array if duplicate is not found
    if ($flag == 0) {
        $array[$i][0] = $name;
        $array[$i][1] = $age;
    } else {
        $i = $i - 1;
    }

}
$duration = time - $start;
print ("Array Execution Time: ", $duration, "s \n");
