total_Records=10.0
numGolfRecords=4.0
unConditionalprobGolf=numGolfRecords / total_Records
print("Unconditional probability of golf: ={}".format(unConditionalprobGolf)) 

#conditional probability of 'single' given 'medRisk'
numMedRiskSingle=2.0
numMedRisk=3.0
probMedRiskSingle=numMedRiskSingle/total_Records
probMedRisk=numMedRisk/total_Records
conditionalProb=(probMedRiskSingle/probMedRisk)
print("Conditional probability of single given medRisk: = {}".format(conditionalProb))