SELECT user_id AS buyer_id,
       join_date,
       SUM(IF(YEAR(order_date) = 2019, 1, 0)) AS orders_in_2019
FROM Users LEFT JOIN Orders ON Users.user_id = Orders.buyer_id #LEFT JOIN Items USING(item_id)
GROUP BY 1, 2
ORDER BY buyer_id ASC

/*SELECT 
   U.USER_ID AS buyer_id,     
   U.JOIN_DATE AS join_date,
   SUM(
       IF(YEAR(ORDER_DATE) = 2019, 1, 0)) AS orders_in_2019    
FROM USERS U
LEFT JOIN ORDERS O
   ON U.USER_ID = O.BUYER_ID 
GROUP BY 
   U.USER_ID, 
   U.JOIN_DATE*/