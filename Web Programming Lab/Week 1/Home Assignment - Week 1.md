# 220962063 - Sambhav Nath Jain
Home Assignment - WEEK 1
<br>
Date: 14 January 2025 
<br>
Time: 11:35PM

<b>Question: </b>
<img src="HWQn.png">

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Conference Registration Form</title>
</head>
<body>
    <h1>Conference Registration Form</h1>
    <form action="submit_registration" method="post" enctype="multipart/form-data">

        <!-- Participant Details -->
        <fieldset>
            <legend>Participant Details</legend>

            <label for="fullName">Full Name:</label>
            <input type="text" id="fullName" name="fullName" placeholder="Enter your full name" required><br><br>

            <label for="email">Email:</label>
            <input type="email" id="email" name="email" placeholder="example@domain.com" required><br><br>

            <label for="phoneNumber">Phone Number:</label>
            <input type="tel" id="phoneNumber" name="phoneNumber" pattern="\d{10}" placeholder="1234567890" required><br><br>

            <label for="age">Age:</label>
            <input type="number" id="age" name="age" min="18" max="60" required><br><br>
        </fieldset>

        <!-- Event Preferences -->
        <fieldset>
            <legend>Event Preferences</legend>

            <label for="events">Select Events:</label>
            <select id="events" name="events" multiple required>
                <option value="coding">Coding Contest</option>
                <option value="hackathon">Hackathon</option>
                <option value="paper">Paper Presentation</option>
                <option value="robotics">Robotics Challenge</option>
                <option value="keynote">Keynote Session</option>
            </select>
            <p>Hold Ctrl (Windows) or Command (Mac) to select multiple options.</p>
        </fieldset>

        <!-- Accommodation Details -->
        <fieldset>
            <legend>Accommodation Details</legend>

            <label>Accommodation Type:</label><br>
            <input type="radio" id="hostel" name="accommodation" value="hostel" required>
            <label for="hostel">Hostel</label><br>

            <input type="radio" id="hotel" name="accommodation" value="hotel" required>
            <label for="hotel">Hotel</label><br>

            <input type="radio" id="none" name="accommodation" value="none" required>
            <label for="none">None</label><br><br>
        </fieldset>

        <!-- Dietary Preferences -->
        <fieldset>
            <legend>Dietary Preferences</legend>

            <input type="checkbox" id="vegetarian" name="diet[]" value="vegetarian">
            <label for="vegetarian">Vegetarian</label><br>

            <input type="checkbox" id="nonVegetarian" name="diet[]" value="non-vegetarian">
            <label for="nonVegetarian">Non-Vegetarian</label><br>

            <input type="checkbox" id="vegan" name="diet[]" value="vegan">
            <label for="vegan">Vegan</label><br>

            <input type="checkbox" id="otherDiet" name="diet[]" value="other" onclick="toggleOtherDiet()">
            <label for="otherDiet">Other (Specify below)</label><br>

            <input type="text" id="otherDietText" name="otherDietText" placeholder="Specify other preferences" disabled><br><br>
        </fieldset>

        <!-- Additional Info -->
        <fieldset>
            <legend>Additional Info</legend>

            <label for="upload">Upload Student ID (PDF only, max 5 MB):</label>
            <input type="file" id="upload" name="upload" accept="application/pdf" required><br><br>

            <label for="comments">Comments/Requests:</label><br>
            <textarea id="comments" name="comments" maxlength="300" placeholder="Write your comments here..."></textarea><br><br>
        </fieldset>

        <!-- Consent and Submission -->
        <fieldset>
            <legend>Consent and Submission</legend>

            <input type="checkbox" id="consent" name="consent" required>
            <label for="consent">I agree to the terms and conditions.</label><br><br>

            <button type="submit">Submit</button>
            <button type="reset">Reset</button>
        </fieldset>

    </form>
</body>
</html>
```

<img src="HWQn-Output.png"  >