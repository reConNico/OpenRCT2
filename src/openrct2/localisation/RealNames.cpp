/*****************************************************************************
 * Copyright (c) 2014-2023 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#include "Localisation.h"

const char real_name_initials[] = {
    'B', 'C', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'M', 'N', 'P', 'R', 'S', 'T', 'W',
};

// clang-format off
// The peep sorter assumes this array is alphabetically ordered
const char *real_names[] = {
    "Aaron",
    "Abdul",
    "Abraham",
    "Abu",
    "Adam",
    "Adrian",
    "Adriane",
    "Aileen",
    "Aisha",
    "Akiko",
    "Akira",
    "Al",
    "Alan",
    "Alana",
    "Albert",
    "Alberta",
    "Alec",
    "Alesia",
    "Alex",
    "Alexa",
    "Alexander",
    "Alexandra",
    "Alexis",
    "Alf",
    "Alfonso",
    "Alfred",
    "Ali",
    "Alice",
    "Alicia",
    "Alison",
    "Alistair",
    "Allan",
    "Allen",
    "Allison",
    "Allister",
    "Alma",
    "Alvin",
    "Alyson",
    "Amanda",
    "Amber",
    "Amilio",
    "Amos",
    "Amy",
    "Ana",
    "Anabel",
    "Anastasia",
    "Andie",
    "Andrea",
    "Andres",
    "Andrew",
    "Andy",
    "Angel",
    "Angela",
    "Angelica",
    "Angie",
    "Angus",
    "Anika",
    "Ann",
    "Anna",
    "Anne",
    "Annette",
    "Annie",
    "Annika",
    "Anthony",
    "Anton",
    "Antonio",
    "April",
    "Archer",
    "Archie",
    "Arlene",
    "Arnie",
    "Arnold",
    "Art",
    "Arthur",
    "Asaf",
    "Ashley",
    "Astrid",
    "Aubrey",
    "Austin",
    "Austine",
    "Avon",
    "Avril",
    "Axel",
    "Aziz",
    "Bailey",
    "Barbara",
    "Barney",
    "Barry",
    "Bart",
    "Barton",
    "Baxter",
    "Beck",
    "Becket",
    "Becky",
    "Belinda",
    "Bella",
    "Belle",
    "Ben",
    "Benjamin",
    "Benny",
    "Bernadette",
    "Bernard",
    "Bernard",
    "Bernardette",
    "Bernice",
    "Bernice",
    "Berty",
    "Bess",
    "Beth",
    "Bethany",
    "Bette",
    "Betty",
    "Bev",
    "Beverley",
    "Beverly",
    "Bianca",
    "Bill",
    "Billie",
    "Billy",
    "Bjorn",
    "Blaire",
    "Blake",
    "Blanche",
    "Bo",
    "Bob",
    "Bobbie",
    "Bobby",
    "Bonnie",
    "Boris",
    "Brad",
    "Bradley",
    "Brady",
    "Brandi",
    "Brandon",
    "Brandy",
    "Brenda",
    "Brendan",
    "Brendon",
    "Brent",
    "Brett",
    "Brian",
    "Bridgit",
    "Brigitte",
    "Britney",
    "Bruce",
    "Bruno",
    "Brutus",
    "Bryan",
    "Buck",
    "Bucky",
    "Bug",
    "Burton",
    "Byron",
    "Cailin",
    "Caitlyn",
    "Cal",
    "Caley",
    "Callum",
    "Calvin",
    "Cameron",
    "Camille",
    "Campbell",
    "Candy",
    "Carl",
    "Carla",
    "Carlene",
    "Carlos",
    "Carmela",
    "Carmen",
    "Carol",
    "Carole",
    "Caroline",
    "Carolyn",
    "Carrie",
    "Casey",
    "Cassandra",
    "Cassey",
    "Cassie",
    "Catherina",
    "Catherine",
    "Cathy",
    "Caz",
    "Cecelia",
    "Cecil",
    "Cecille",
    "Ceilidh",
    "Celeste",
    "Chad",
    "Charlene",
    "Charles",
    "Charlie",
    "Charlotte",
    "Chelsea",
    "Cher",
    "Cheri",
    "Cheryll",
    "Chip",
    "Chloe",
    "Chris",
    "Christel",
    "Christian",
    "Christie",
    "Christina",
    "Christine",
    "Christopher",
    "Chuck",
    "Cindy",
    "Clair",
    "Claire",
    "Clara",
    "Clarabell",
    "Clark",
    "Claude",
    "Claudette",
    "Claudia",
    "Clayton",
    "Cliff",
    "Clifford",
    "Clint",
    "Clive",
    "Clyde",
    "Codey",
    "Cody",
    "Colin",
    "Colleen",
    "Connie",
    "Coral",
    "Corina",
    "Craig",
    "Curtis",
    "Cynthia",
    "Cyril",
    "Daisy",
    "Dale",
    "Damien",
    "Damon",
    "Dan",
    "Dana",
    "Daniel",
    "Danielle",
    "Danni",
    "Danny",
    "Daphne",
    "Darby",
    "Darla",
    "Darlene",
    "Darrell",
    "Darren",
    "Darryl",
    "Dave",
    "David",
    "Davie",
    "Davis",
    "Dawn",
    "Dean",
    "Debbie",
    "Debby",
    "Deborah",
    "Debra",
    "Debs",
    "Deidre",
    "Delores",
    "Denise",
    "Dennis",
    "Denzel",
    "Derek",
    "Desmond",
    "Diana",
    "Diane",
    "Dianna",
    "Dick",
    "Dillon",
    "Dina",
    "Dominic",
    "Dominik",
    "Don",
    "Donald",
    "Donna",
    "Donovan",
    "Doreen",
    "Doris",
    "Dorothy",
    "Doug",
    "Dougal",
    "Douglas",
    "Doyle",
    "Drew",
    "Duane",
    "Dudley",
    "Duncan",
    "Dwight",
    "Dylan",
    "Earl",
    "Ed",
    "Eddie",
    "Edgar",
    "Edith",
    "Edmond",
    "Edward",
    "Edwin",
    "Edwina",
    "Eileen",
    "Elaine",
    "Elina",
    "Elisa",
    "Elisabeth",
    "Eliza",
    "Elizabeth",
    "Ella",
    "Ellen",
    "Elmer",
    "Elsie",
    "Emile",
    "Emilio",
    "Emily",
    "Emma",
    "Emmett",
    "Enrique",
    "Eric",
    "Erica",
    "Ericka",
    "Erik",
    "Erika",
    "Erin",
    "Erinn",
    "Ernest",
    "Esmeralda",
    "Esta",
    "Estella",
    "Esther",
    "Ethan",
    "Eugene",
    "Eva",
    "Evan",
    "Eve",
    "Evelyn",
    "Everett",
    "Fabio",
    "Falicia",
    "Farah",
    "Felicity",
    "Felix",
    "Fergus",
    "Fernando",
    "Fidelia",
    "Finlay",
    "Fiona",
    "Fletcher",
    "Flora",
    "Florence",
    "Floyd",
    "Fly",
    "Frances",
    "Francesca",
    "Francis",
    "Francisco",
    "Frank",
    "Franklin",
    "Franky",
    "Fraser",
    "Fred",
    "Freda",
    "Freddy",
    "Fuzz",
    "Gabriel",
    "Gabriela",
    "Gail",
    "Garrett",
    "Garth",
    "Gary",
    "Gavin",
    "Gayle",
    "Gene",
    "Genevieve",
    "Geoff",
    "Geoffrey",
    "George",
    "Gerald",
    "Geraldine",
    "Gerard",
    "Geri",
    "Gerry",
    "Gilbert",
    "Gillian",
    "Gina",
    "Ginger",
    "Giuseppe",
    "Gladys",
    "Glen",
    "Glenda",
    "Glenn",
    "Gloria",
    "Glyne",
    "Goldie",
    "Gordon",
    "Grace",
    "Graeme",
    "Graham",
    "Grant",
    "Grayson",
    "Greg",
    "Gregor",
    "Gregory",
    "Gretchen",
    "Gus",
    "Guy",
    "Gwen",
    "Gwendoline",
    "Hadrian",
    "Hamish",
    "Hank",
    "Hannah",
    "Hans",
    "Harley",
    "Harold",
    "Harry",
    "Harvey",
    "Haseem",
    "Hayley",
    "Hazel",
    "Heather",
    "Hector",
    "Heidi",
    "Helen",
    "Helena",
    "Henri",
    "Henry",
    "Herbert",
    "Herbie",
    "Hermann",
    "Hilda",
    "Hollie",
    "Holly",
    "Homer",
    "Horace",
    "Howard",
    "Hugh",
    "Hugo",
    "Iain",
    "Ian",
    "Imani",
    "Imelda",
    "Imran",
    "Ingrid",
    "Irene",
    "Irma",
    "Irving",
    "Isaac",
    "Isabella",
    "Isabelle",
    "Ishan",
    "Isla",
    "Ivan",
    "Ivanna",
    "Ivy",
    "Izola",
    "Jack",
    "Jacob",
    "Jacque",
    "Jacqueline",
    "Jacqui",
    "Jake",
    "Jakob",
    "James",
    "Jan",
    "Jane",
    "Janet",
    "Janice",
    "Jason",
    "Jasper",
    "Jay",
    "Jayne",
    "Jean",
    "Jeanette",
    "Jeff",
    "Jeffrey",
    "Jennifer",
    "Jenny",
    "Jeremy",
    "Jerry",
    "Jesse",
    "Jessica",
    "Jessie",
    "Jessy",
    "Jill",
    "Jillian",
    "Jim",
    "Jimbo",
    "Jimmy",
    "Jo",
    "Joan",
    "Joann",
    "Joanne",
    "Jock",
    "Jodi",
    "Joe",
    "Joel",
    "Joelyn",
    "Joey",
    "Johan",
    "John",
    "Johnathan",
    "Johnnie",
    "Johnny",
    "Jolynn",
    "Jon",
    "Jonah",
    "Jonas",
    "Jonathan",
    "Joni",
    "Jonny",
    "Jordan",
    "Jorge",
    "Jose",
    "Joseph",
    "Josephine",
    "Josh",
    "Joshua",
    "Joyce",
    "Juan",
    "Juana",
    "Juanita",
    "Judge",
    "Judie",
    "Judith",
    "Judy",
    "Julia",
    "Julian",
    "Julie",
    "Juliette",
    "Julio",
    "Julius",
    "June",
    "Justin",
    "Kaitlyn",
    "Kaley",
    "Kandice",
    "Kara",
    "Kareen",
    "Karen",
    "Karl",
    "Karolyne",
    "Karri",
    "Kate",
    "Katelyn",
    "Katey",
    "Katherine",
    "Kathie",
    "Kathleen",
    "Kathryn",
    "Kathy",
    "Katie",
    "Katrina",
    "Katy",
    "Katya",
    "Kay",
    "Keiko",
    "Keith",
    "Kelly",
    "Kelsey",
    "Ken",
    "Kenneth",
    "Kenny",
    "Kerry",
    "Kev",
    "Kevin",
    "Kieran",
    "Kim",
    "Kimberly",
    "Kiriaki",
    "Kirk",
    "Klaus",
    "Kris",
    "Krista",
    "Kristian",
    "Kristy",
    "Kurt",
    "Kurtis",
    "Kyle",
    "Kylie",
    "Laila",
    "Lana",
    "Lance",
    "Larry",
    "Lasse",
    "Latisha",
    "Laura",
    "Lauren",
    "Laurie",
    "Lauryn",
    "Lawrence",
    "Leah",
    "Lee",
    "Leigh",
    "Len",
    "Lena",
    "Lenore",
    "Leo",
    "Leon",
    "Leonard",
    "Leonardo",
    "Leone",
    "Leroy",
    "Les",
    "Lesley",
    "Leslie",
    "Lester",
    "Lewis",
    "Liam",
    "Lillian",
    "Lilly",
    "Lily",
    "Linda",
    "Lindsay",
    "Lindsey",
    "Lisa",
    "Lita",
    "Logan",
    "Lone",
    "Loren",
    "Loretta",
    "Lori",
    "Lorraine",
    "Lottie",
    "Louis",
    "Louise",
    "Lowell",
    "Lucas",
    "Lucy",
    "Luis",
    "Luke",
    "Luther",
    "Lydia",
    "Lynn",
    "Lynne",
    "Lyssa",
    "Mabel",
    "Madeline",
    "Maggie",
    "Magnus",
    "Mahamed",
    "Malcolm",
    "Mandy",
    "Manuel",
    "Marc",
    "Marcela",
    "Marci",
    "Marcia",
    "Marco",
    "Marcus",
    "Marcy",
    "Margaret",
    "Margarita",
    "Maria",
    "Mariah",
    "Marian",
    "Marianna",
    "Marie",
    "Marilyn",
    "Marina",
    "Marion",
    "Marisa",
    "Marissa",
    "Marjorie",
    "Mark",
    "Markus",
    "Marlene",
    "Marlin",
    "Marlon",
    "Marshall",
    "Martha",
    "Martin",
    "Martyn",
    "Marvin",
    "Mary",
    "Mathew",
    "Matt",
    "Matthew",
    "Maude",
    "Maureen",
    "Maurice",
    "Mauricio",
    "Mavis",
    "Max",
    "Maxine",
    "May",
    "Megan",
    "Meghan",
    "Mel",
    "Melanie",
    "Melany",
    "Melinda",
    "Melissa",
    "Melody",
    "Melvin",
    "Mervin",
    "Mhairi",
    "Mia",
    "Michael",
    "Michelle",
    "Mick",
    "Mickey",
    "Miguel",
    "Mikael",
    "Mike",
    "Mikey",
    "Miki",
    "Mikko",
    "Mildred",
    "Millie",
    "Milly",
    "Milton",
    "Miranda",
    "Miriam",
    "Mirriam",
    "Mitchell",
    "Mo",
    "Molly",
    "Monica",
    "Monique",
    "Monty",
    "Morgan",
    "Morris",
    "Morten",
    "Moses",
    "Muriel",
    "Murphy",
    "Murray",
    "Mustafa",
    "Myles",
    "Myrissa",
    "Myrtle",
    "Nadine",
    "Nancy",
    "Nanette",
    "Naomi",
    "Natalia",
    "Natalie",
    "Natasha",
    "Nathan",
    "Nathaniel",
    "Neil",
    "Nellie",
    "Nelly",
    "Nelson",
    "Neville",
    "Nicholas",
    "Nichole",
    "Nick",
    "Nico",
    "Nicola",
    "Nicolas",
    "Nicole",
    "Nigel",
    "Nikia",
    "Nikki",
    "Nina",
    "Noah",
    "Noel",
    "Norma",
    "Norman",
    "Norris",
    "Norvall",
    "Olga",
    "Olive",
    "Oliver",
    "Ollie",
    "Omar",
    "Oona",
    "Orve",
    "Orville",
    "Oscar",
    "Otto",
    "Owen",
    "Paisley",
    "Pam",
    "Pamela",
    "Pandora",
    "Pat",
    "Patricia",
    "Patrick",
    "Patty",
    "Paul",
    "Paula",
    "Pauline",
    "Pedro",
    "Peggy",
    "Penelope",
    "Penny",
    "Perry",
    "Pete",
    "Peter",
    "Phil",
    "Philip",
    "Phillip",
    "Phyllis",
    "Polly",
    "Preston",
    "Qasim",
    "Quentin",
    "Quinn",
    "Rachel",
    "Rae",
    "Rafael",
    "Raj",
    "Raja",
    "Ralph",
    "Ramon",
    "Randal",
    "Raquel",
    "Rashid",
    "Raul",
    "Ray",
    "Raymond",
    "Raymondo",
    "Rebecca",
    "Reg",
    "Regina",
    "Reginald",
    "Reinhold",
    "Rene",
    "Reuben",
    "Rex",
    "Rhonda",
    "Richard",
    "Rick",
    "Ricky",
    "Rita",
    "Robb",
    "Robert",
    "Roberta",
    "Robin",
    "Robina",
    "Robyn",
    "Robynne",
    "Rock",
    "Rockie",
    "Rod",
    "Rodney",
    "Rodrigo",
    "Roger",
    "Roland",
    "Rolf",
    "Romeo",
    "Ronald",
    "Ronan",
    "Ronnie",
    "Rosalind",
    "Rosanna",
    "Rosanned",
    "Rose",
    "Rosemary",
    "Rosetta",
    "Rosie",
    "Ross",
    "Rosty",
    "Roxanne",
    "Roy",
    "Ruben",
    "Ruby",
    "Russell",
    "Ruth",
    "Ryan",
    "Sabrina",
    "Sadie",
    "Sally",
    "Sam",
    "Samantha",
    "Sammy",
    "Samuel",
    "Sandra",
    "Sandy",
    "Sara",
    "Sarah",
    "Sasha",
    "Saul",
    "Scot",
    "Scott",
    "Sean",
    "Sebastian",
    "Sergio",
    "Shakira",
    "Shannon",
    "Shari",
    "Sharnell",
    "Sharon",
    "Sharyn",
    "Shawn",
    "Shelby",
    "Shelley",
    "Sherene",
    "Sheri",
    "Sherman",
    "Sherry",
    "Sheryl",
    "Shirley",
    "Shivani",
    "Shona",
    "Sian",
    "Sid",
    "Sidney",
    "Simon",
    "Sindy",
    "Sinead",
    "Sofia",
    "Sonja",
    "Sonny",
    "Sonya",
    "Sophia",
    "Sophie",
    "Spencer",
    "Stacey",
    "Stan",
    "Stanley",
    "Stefan",
    "Stephanie",
    "Stephen",
    "Steve",
    "Steven",
    "Stewart",
    "Stuart",
    "Sue",
    "Suki",
    "Susan",
    "Susana",
    "Susanne",
    "Susie",
    "Suzanne",
    "Sven",
    "Sylvester",
    "Sylvia",
    "Tabatha",
    "Tamara",
    "Tammie",
    "Tamsin",
    "Tania",
    "Tanya",
    "Tara",
    "Taylor",
    "Ted",
    "Teresa",
    "Terrance",
    "Terry",
    "Tess",
    "Tessa",
    "Tex",
    "Thelma",
    "Theodore",
    "Theresa",
    "Thomas",
    "Tiffany",
    "Tiger",
    "Tiko",
    "Tillie",
    "Tim",
    "Timmy",
    "Timothy",
    "Tina",
    "Toby",
    "Todd",
    "Tom",
    "Tomaki",
    "Tommy",
    "Tonia",
    "Tonie",
    "Tony",
    "Tracy",
    "Travis",
    "Trevor",
    "Tricia",
    "Trixie",
    "Troy",
    "Tucker",
    "Tyler",
    "Tyson",
    "Ulysses",
    "Uri",
    "Val",
    "Valerie",
    "Vanessa",
    "Vani",
    "Vaughn",
    "Velma",
    "Vernon",
    "Veronica",
    "Vicki",
    "Vicky",
    "Victor",
    "Victoria",
    "Vijay",
    "Vince",
    "Vincent",
    "Vinnie",
    "Virginia",
    "Viv",
    "Vivian",
    "Viviene",
    "Wally",
    "Walt",
    "Walter",
    "Walton",
    "Wanda",
    "Warren",
    "Wayne",
    "Wendell",
    "Wendy",
    "Wes",
    "Wesley",
    "Whitney",
    "Will",
    "William",
    "Willie",
    "Willis",
    "Wilson",
    "Winston",
    "Wyatt",
    "Xavier",
    "Yasmin",
    "Yogi",
    "Ysabel",
    "Yvonne",
    "Zachary",
    "Zachery",
    "Zola",
};
// clang-format on
