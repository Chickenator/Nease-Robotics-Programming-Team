#include <Joystick.h>
#include <SampleRobot.h>
#include <Talon.h>
#include <Timer.h>
#include <XboxController.h>
#include <Spark.h>

/**
 * This sample program shows how to control a motor using a joystick. In the
 * operator control part of the program, the joystick is read and the value is
 * written to the motor.
 *
 * Joystick analog values range from -1 to 1 and speed controller inputs as
 * range from -1 to 1 making it easy to work together. The program also delays a
 * short time in the loop to allow other threads to run. This is generally a
 * good idea, especially since the joystick values are only transmitted from the
 * Driver Station once every 20ms.
 */
class Robot: public frc::SampleRobot {
public:
	/**
	 * Runs the motor from the output of a Joystick.
	 */
	void OperatorControl() {
		while (IsOperatorControl() && IsEnabled()) {
			/* Set the motor controller's output. This takes a number from -1
			 * (100% speed in reverse) to +1 (100% speed forwards).
			 */
			m_motor.Set(m_stick.GetY());

			frc::Wait(kUpdatePeriod);  // Wait 5ms for the next update.
		}
	}

private:
	// Initialize Joystick on port 0
	frc::Joystick m_stick { 0 };

	/* The motor to control with the Joystick. This uses a Talon speed
	 * controller; use the Victor or Jaguar classes for other speed controllers.
	 *
	 * Initialize the Talon on channel 0
	 */
	frc::Spark m_motor { 0 };

	// Update every 0.005 seconds/5 milliseconds.
	static constexpr double kUpdatePeriod = 0.005;
};

START_ROBOT_CLASS(Robot)
