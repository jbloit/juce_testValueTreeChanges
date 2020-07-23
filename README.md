# Juce Value Tree callback test



Purpose is to answer this question:

When replacing a value tree by another one, do all the properties trigger the property change callback, or only the ones whose value have changed?



Answer: on the properties with values that have changed trigger the propertyChange callback.



