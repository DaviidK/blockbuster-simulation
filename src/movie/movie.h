// ---------------------------------- movie.h ----------------------------------
// David Kang
// -----------------------------------------------------------------------------
// Purpose: This class defines a singular Movie object. The movie will contain
// information on the genre, director, title, release year, and current stock in
// the store. Depending on the type of movie object created, more information
// may also be stored. All Movie objects will be comparable to other Movies of
// the same genre.
// -----------------------------------------------------------------------------
// Assumptions:
//  - All input data will be provided in the following format:
//     genre(string) stock(int) director(string) title(string) 
//       In addition, the following movie genre's input will also contain:
//         Comedy: releaseYear(int) 
//         Drama: releaseYear(int)
//         Classics: majorActor(string) releaseMonth(int) releaseYear(int)