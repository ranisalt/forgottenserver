function handleRequest(req, res)
    local json = req:json()
    if type(json) ~= "table" then
        return
    end

    local type_ = json["type"]
    if type_ ~= "login" then
        return res:json({
            errorCode = 1,
            errorMessage = "Invalid request type."
        })
    end

    local email, password = json["email"], json["password"]
    if type(email) ~= "string" or type(password) ~= "string" then
        return res:json({
            errorCode = 3,
            errorMessage = "Tibia account email address or Tibia password is not correct."
        })
    end
end
