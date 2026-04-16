CREATE OR REPLACE FUNCTION search_contacts(p_pattern TEXT)
RETURNS TABLE(name VARCHAR, surname VARCHAR, phone VARCHAR) AS $$
BEGIN
    RETURN QUERY
    SELECT name, surname, phone
    FROM contacts
    WHERE name ILIKE '%' || p_pattern || '%'
       OR surname ILIKE '%' || p_pattern || '%'
       OR phone ILIKE '%' || p_pattern || '%';
END;
$$ LANGUAGE plpgsql;


CREATE OR REPLACE FUNCTION get_contacts_paginated(p_limit INT, p_offset INT)
RETURNS TABLE(name VARCHAR, surname VARCHAR, phone VARCHAR) AS $$
BEGIN
    RETURN QUERY
    SELECT name, surname, phone
    FROM contacts
    ORDER BY name
    LIMIT p_limit OFFSET p_offset;
END;
$$ LANGUAGE plpgsql;