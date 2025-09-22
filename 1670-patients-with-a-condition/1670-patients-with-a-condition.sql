SELECT patient_id,
       patient_name,
       conditions
FROM Patients AS t1
WHERE conditions LIKE 'DIAB1%' OR conditions LIKE '% DIAB1%'
#GROUP BY player_id
#ORDER BY recovery_time ASC, patient_name ASC