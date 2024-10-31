# Write your MySQL query statement below
select p.firstname,p.lastname,a.city,a.state from Person p Left Join Address a On p.personId = a.personId