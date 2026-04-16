CREATE OR REPLACE PROCEDURE upsert_contact(
    p_name VARCHAR,
    p_surname VARCHAR,
    p_phone VARCHAR
)
LANGUAGE plpgsql AS $$
BEGIN
    IF EXISTS (
        SELECT 1 FROM contacts
        WHERE name = p_name AND surname = p_surname
    ) THEN
        UPDATE contacts
        SET phone = p_phone
        WHERE name = p_name AND surname = p_surname;
    ELSE
        INSERT INTO contacts(name, surname, phone)
        VALUES (p_name, p_surname, p_phone);
    END IF;
END;
$$;


CREATE OR REPLACE PROCEDURE bulk_insert_contacts(
    p_names TEXT[],
    p_surnames TEXT[],
    p_phones TEXT[]
)
LANGUAGE plpgsql AS $$
DECLARE
    i INT;
BEGIN
    FOR i IN 1..array_length(p_names, 1) LOOP

        IF p_phones[i] ~ '^[0-9]{10,15}$' THEN
            CALL upsert_contact(
                p_names[i],
                p_surnames[i],
                p_phones[i]
            );
        ELSE
            RAISE NOTICE 'Invalid: % % (%)',
            p_names[i], p_surnames[i], p_phones[i];
        END IF;

    END LOOP;
END;
$$;


CREATE OR REPLACE PROCEDURE delete_contact(p_value TEXT)
LANGUAGE plpgsql AS $$
BEGIN
    DELETE FROM contacts
    WHERE name = p_value
       OR surname = p_value
       OR phone = p_value;
END;
$$;