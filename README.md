# PICRUSt
# Language: C++
# Input: TXT
# Output: PREFIX
# Tested with: PluMA 1.1, GCC 4.8.4
# Dependency: PICRUSt 1.1.4

PluMA plugin to predict functional content in a set of sequences using marker genes with PICRUSt (Langille et al, 2013).

The plugin accepts as input a TXT file of parameters, containing whitespace-delimited keyword-value pairs:
abundances: File of taxa abundances (BIOM)
functions: Enzyme classification numbers for marker genes (TSV)
markers: Predicted marker genes (TSV)

The pipeline then generates two files, prefixed by the user-specified PREFIX:
seqtab_norm.tsv: ASV abundance table
pred_metagenome_unstrat.tsv: Enzyme classification numbers per sample

Example files are those provided with the PICRUSt2 tutorial.
