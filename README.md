# Blockbuster-Simulation
This program simulates the activity of an automated inventory system for a video rental store. It populates the inventory and customers from designated input files, then processes a sequence of commands to track all transactions.

## Design
### Movies
In this model movies are categorized into three different genres: classics, comedies, and dramas. Each movie will be stored alongside identifying information, including: the title, director, release year, and number in stock. In addition to this information, classics will also store the lead actor for each film. 

### Customers 
Customers in this will be stored with a first and last name, as well as a four-digit unique ID number. Each customer will be capable of borrowing or returning a film, and their activity will be tracked by the program as it runs through different actions.

### Actions
When simulating activity, four different actions will be permitted in this program: 
1. Borrowing a film, which will 