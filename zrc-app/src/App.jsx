import { Button, Container, Typography } from "@mui/material";
import axios from "axios";
import { useState } from "react";

function App() {
  const [camaraState, setCameraState] = useState(false);
  const [meetingAccepted, setMeetingAccepted] = useState(false);

  const handleAudioClick = async () => {
    try {
      const response = await axios({
        method: "POST",
        url: "/api/toggle-camera",
        data: {
          cameraState: !camaraState,
        },
        headers: {
          "Content-Type": "application/json",
        },
      });
      console.log(response.data);
      setCameraState(!camaraState);
    } catch (e) {
      console.error("Error toggling camera:", e);
    }
  };

  const handleMeetingAccept = async () => {
    try {
      const response = await axios({
        method: "GET",
        url: "/api/accept-meeting",
        headers: {
          "Content-Type": "application/json",
        },
      });
      console.log(response.data);
      if (response.status == 202) {
        setMeetingAccepted(true);
      }
    } catch (e) {
      console.error("Error joining meeting:", e);
    }
  };

  return (
    <Container
      disableGutters
      maxWidth={false}
      sx={{
        width: "80%",
        minWidth: "300px",
        minHeight: "100vh",
        display: "flex",
        flexDirection: "column",
        justifyContent: "center",
        alignItems: "center",
        textAlign: "center",
        backgroundColor: "#303030",
        overflowX: "hidden",
      }}
    >
      <Typography variant="h2" sx={{ marginBottom: 10 }}>
        Zoom Rooms Controller App
      </Typography>
      <Typography variant="h4" sx={{ marginBottom: 5 }}>
        Zoom Room Name (replace later)
      </Typography>
      {!meetingAccepted ? (
        <Button
          sx={{ marginBottom: 4 }}
          variant="contained"
          onClick={handleMeetingAccept}
        >
          Accept Meeting
        </Button>
      ) : null}
      <Button variant="contained" onClick={handleAudioClick}>
        Toggle Zoom Rooms Camera
      </Button>
    </Container>
  );
}

export default App;
