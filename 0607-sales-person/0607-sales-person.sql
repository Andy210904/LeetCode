SELECT Distinct s.name
FROM SalesPerson s
LEFT JOIN Orders o ON s.sales_id = o.sales_id
LEFT JOIN Company c ON o.com_id = c.com_id
where (c.name is NULL OR c.name != 'RED') AND s.name not in (Select s.name from SalesPerson s LEFT JOIN Orders o ON s.sales_id = o.sales_id
LEFT JOIN Company c ON o.com_id = c.com_id where c.name ='RED');
