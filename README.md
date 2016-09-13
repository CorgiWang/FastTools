# FastTools usage


1. Extract quality data from FastQ file

	e.g.	FastTools -eQ XXX.FQ

	This command will genarate a new file named XXX.FQ.Qual, which contains the quality data in XXX.FQ.



2. Resolve quality file with DCT

	e.g.	FastTools -r XXX.FQ.Qual

	This command will genarate TWO new files named XXX.FQ.Qual.A (Auxiliary) & XXX.FQ.Qual.B (Background).



3. Merge into quality file with IDCT

	e.g.	FastTools -m XXX.FQ.Qual

	This command will load XXX.FQ.Qual.A & XXX.FQ.Qual.B, and then merge them into XXX.FQ.Qual.

