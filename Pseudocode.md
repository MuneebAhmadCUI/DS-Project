// ==========================================
// FUNCTION 1: AddPassenger (Contributor: Muneeb)
// ==========================================
FUNCTION AddPassenger():
    PROMPT user for Name, Age, Gender, Train, Source, Destination
    CREATE new Node named 'newPassenger'
    SET newPassenger.TicketID = global_NextTicketID
    INCREMENT global_NextTicketID
    SET newPassenger.Data = User Inputs
    SET newPassenger.Next = NULL

    IF Head IS NULL THEN
        SET Head = newPassenger
    ELSE
        SET Temp = Head
        WHILE Temp.Next IS NOT NULL DO
            SET Temp = Temp.Next
        ENDWHILE
        SET Temp.Next = newPassenger
    ENDIF
    PRINT "Ticket Booked Successfully"
ENDFUNCTION

// ==========================================
// FUNCTION 2: CancelTicket (Contributor: Iman)
// ==========================================
FUNCTION CancelTicket():
    IF Head IS NULL THEN
        PRINT "No reservations found"
        RETURN
    ENDIF

    PROMPT user for TicketID_To_Cancel
    SET Temp = Head
    SET Prev = NULL

    // Traverse to find the node
    WHILE Temp IS NOT NULL AND Temp.TicketID != TicketID_To_Cancel DO
        SET Prev = Temp
        SET Temp = Temp.Next
    ENDWHILE

    IF Temp IS NULL THEN
        PRINT "Ticket ID not found"
        RETURN
    ENDIF

    // Unlinking the node
    IF Prev IS NULL THEN
        SET Head = Temp.Next  // Deleting the first node
    ELSE
        SET Prev.Next = Temp.Next // Deleting middle or last node
    ENDIF

    DELETE Temp
    PRINT "Ticket Cancelled Successfully"
ENDFUNCTION

// ==========================================
// FUNCTION 3: SearchPassenger (Contributor: Moosa)
// ==========================================
FUNCTION SearchPassenger():
    IF Head IS NULL THEN
        PRINT "List is empty"
        RETURN
    ENDIF

    PROMPT user for SearchID
    SET Temp = Head

    WHILE Temp IS NOT NULL DO
        IF Temp.TicketID == SearchID THEN
            PRINT Temp.Name, Temp.Age, Temp.Train
            RETURN
        ENDIF
        SET Temp = Temp.Next
    ENDWHILE

    PRINT "Ticket ID not found"
ENDFUNCTION

// ==========================================
// FUNCTION 4: SortPassengers (Contributor: Faisal)
// ==========================================
FUNCTION SortPassengers():
    IF Head IS NULL OR Head.Next IS NULL THEN
        RETURN // Nothing to sort
    ENDIF

    // Bubble sort logic for Linked List
    FOR Node i = Head TO NULL DO
        FOR Node j = i.Next TO NULL DO
            IF i.Name > j.Name THEN
                SWAP(i.Data, j.Data) // Swap all passenger details
            ENDIF
        ENDFOR
    ENDFOR
    PRINT "Sorted by Name"
ENDFUNCTION

// ==========================================
// FUNCTION 5: DisplayAll (Contributor: Muneeb)
// ==========================================
FUNCTION DisplayAll():
    IF Head IS NULL THEN
        PRINT "No Passengers"
        RETURN
    ENDIF

    PRINT "TicketID | Name | Train | Destination"
    SET Temp = Head
    
    WHILE Temp IS NOT NULL DO
        PRINT Temp.TicketID, Temp.Name, Temp.Train, Temp.Destination
        SET Temp = Temp.Next
    ENDWHILE
ENDFUNCTION
