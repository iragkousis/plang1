fun addXToAll(x,theList) = 
	let 
		fun addX y = y + x 
	in
		map addX theList
	end;

(*Το παραπάνω δημιουργεί πρόβλημα διότι δεν μπορούν να χρησιμοποιήσουν στοίβα. Χρησιμοποιούμε τον σωρό για να επιτύχουμε την διατήρηση του activation μετά την επιστροφή της γλώσσας*)