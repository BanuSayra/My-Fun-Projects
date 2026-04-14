import streamlit as st
from random import randint

st.title("🎯 Asra's Number Guessing Game")
st.write("I'm thinking of a number between **1 and 100**.")
st.write("You have **10 attempts** to guess it!")

# Initialize session state variables
if "number" not in st.session_state:
    st.session_state.number = randint(1, 100)
    st.session_state.attempts = 0
    st.session_state.game_over = False

# Input from user
guess = st.number_input(
    "Make a guess:",
    min_value=1,
    max_value=100,
    step=1,
    disabled=st.session_state.game_over
)

# Guess button
if st.button("Submit Guess") and not st.session_state.game_over:
    st.session_state.attempts += 1

    if st.session_state.attempts > 10:
        st.error(
            f"You've used all your attempts 😢 "
            f"The number was **{st.session_state.number}**."
        )
        st.session_state.game_over = True

    elif guess < st.session_state.number:
        st.warning("📉 Too low! Guess higher.")

    elif guess > st.session_state.number:
        st.warning("📈 Too high! Guess lower.")

    else:
        st.success(f"🎉 You got it! The answer was **{st.session_state.number}**.")
        st.info(f"You guessed it in **{st.session_state.attempts}** attempts.")

        if st.session_state.attempts <= 3:
            st.balloons()
            st.success("🔥 Excellent work! Jackpot!")

        st.session_state.game_over = True

# Restart button
if st.session_state.game_over:
    if st.button("🔄 Play Again"):
        st.session_state.number = randint(1, 100)
        st.session_state.attempts = 0
        st.session_state.game_over = False
