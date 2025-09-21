SELECT book_id,
       title,
       author,
       genre,
       publication_year,
       total_copies AS current_borrowers
FROM library_books AS t1 inner JOIN borrowing_records USING(book_id)
WHERE total_copies = (
    SELECT SUM(IF(return_date IS NULL, 1, 0))
    FROM library_books AS t2 inner JOIN borrowing_records USING(book_id)
    WHERE t1.book_id = t2.book_id
)
GROUP BY 1, 2, 3, 4, 5
ORDER BY current_borrowers DESC, title ASC