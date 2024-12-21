# Write your MySQL query statement below
UPDATE SALARY
SET SEX = CASE
                WHEN SEX = 'f' THEN 'm'
                WHEN SEX = 'm' THEN 'f'
            END;
